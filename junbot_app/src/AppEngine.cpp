#include "AppEngine.h"
#include "AppModel.h"
#include "Common.h"
#include "Constants_Def.h"
#include "Screen_Def.h"
#include "AppEnums.h"
#include "QMLHandler.h"
#include "QmlMQTTClient.h"
#include "QMQTTHandler.h"
#include "RobotModel.h"

AppEngine::AppEngine(QObject *parent)
    : QObject(parent)
{
    m_rootContext = m_engine.rootContext();
}

AppEngine::~AppEngine()
{
}

void AppEngine::initEngine()
{
    connect(QML_HANDLER, &QMLHandler::notifyQMLEvent, this, &AppEngine::handleQmlEvent);
    qmlRegisterUncreatableType<AppEnums>("QmlCustomItem", 1, 0, "ENUMS", "Uncreatable");

    qmlRegisterType<QmlMqttClient>("MqttClient", 1, 0, "MqttClient");
    qRegisterMetaType<RobotNode>("RobotNode");
    qmlRegisterUncreatableType<QmlMqttSubscription>("MqttClient", 1, 0, "MqttSubscription", QLatin1String("Subscriptions are read-only"));

    // set context properties
    m_rootContext->setContextProperty("QmlHandler",     QMLHandler::getInstance());
    m_rootContext->setContextProperty("CONST",          Constants_Def::getInstance());
    m_rootContext->setContextProperty("SCREEN",         ScreenDef::getInstance());
    m_rootContext->setContextProperty("AppModel",       AppModel::getInstance());
    m_rootContext->setContextProperty("QMqttHandler",   QMqttHandler::getInstance());
    m_rootContext->setContextProperty("RobotModel",     RobotModel::getInstance());

    // init MQTT
    initMQTT();
}

void AppEngine::startApplication()
{
    m_engine.load(SCR_DEF->QML_APP());
}

void AppEngine::handleMqttConnected()
{
    m_handler->mqttSubcribe("robot1/login_userInforesponse");
}

void AppEngine::processMqttMessage(const QByteArray &message, const QString &topicName)
{
    LOG_DBG << "Process message:" << message << "in topic:" << topicName;
    if (topicName == "robot1/login_userInforesponse") {
        handleLoginResponse(message);
    } else if (topicName == "robot1/state") {
        processStateResponse(message);
    }
}

void AppEngine::handleQmlEvent(int eventID)
{
    AppEnums::E_EVENT_t event = static_cast<AppEnums::E_EVENT_t>(eventID);
    LOG_INF << "Event:" << event;

    switch (event) {
    case AppEnums::E_EVENT_t::UserClickHome:
        MODEL->setCurrentScreenID(AppEnums::HomeScreen);
        break;
    case AppEnums::E_EVENT_t::UserClickControl:
        MODEL->setCurrentScreenID(AppEnums::ControlScreen);
        break;
    case AppEnums::E_EVENT_t::UserClickInfo:
        MODEL->setCurrentScreenID(AppEnums::InfoScreen);
        break;
    case AppEnums::E_EVENT_t::LoginRequest:
        loginAuthenication();
        break;
    case AppEnums::E_EVENT_t::LogoutRequest:
        handleLogoutRequest();
        break;
    case AppEnums::E_EVENT_t::SendDeliveryNodes:
        sendDeliveryNodes();
        break;
    default:
        break;
    }
}

void AppEngine::initMQTT()
{
    m_handler = QMqttHandler::getInstance();
    m_handler->loadMQTTSetting(Constants_Def::getInstance()->DEVICE_PATH());
    m_handler->initBokerHost(Constants_Def::getInstance()->BROKER_PATH());

    connect(m_handler, &QMqttHandler::mqttMessageChanged, MODEL, &AppModel::setRobotMess);
    connect(m_handler, &QMqttHandler::mqttConnected, this, &AppEngine::handleMqttConnected);
    connect(m_handler, &QMqttHandler::mqttMessageReceived, this, &AppEngine::processMqttMessage);

    LOG_INF << "Hostname: " << MODEL->hostname();
    LOG_INF << "Port: " << MODEL->port();
    m_handler->connectMQTT(MODEL->hostname(), MODEL->port());
}

void AppEngine::initConnection()
{
    LOG_DBG;
    RobotNode node;
    node.ip = "xx.xx.xx.xx";
    node.name = "robot1";
    node.current_state_topic = "robot1/state";
    node.control_topic = "robot1/control";

    m_handler->RobotNodes.push_back(node);
    m_handler->mqttSubcribe(m_handler->RobotNodes.at(0));
    m_handler->mqttSubcribe("robot1/state");
}

void AppEngine::removeConnection()
{
    LOG_DBG;
    RobotNode lastNode = m_handler->RobotNodes.last();
    m_handler->mqttUnsubcribe(lastNode);
    m_handler->mqttUnsubcribe("robot1/state");
    m_handler->RobotNodes.pop_back();
}

void AppEngine::loginAuthenication()
{
#ifdef DUMMY_IGNORE_LOGIN
    MODEL->setLoginStatus(true);
    initConnection();
    MODEL->setCurrentScreenID(AppEnums::E_SCREEN_t::HomeScreen);
#endif
    LOG_DBG << "Username: " << MODEL->userName();
    LOG_DBG << "Password: " << MODEL->password();

    QJsonObject loginData;
    loginData.insert("username", MODEL->userName());
    loginData.insert("password", MODEL->password());
    m_handler->mqttPublish("robot1/login_request", loginData);
}

void AppEngine::handleLogoutRequest()
{
    MODEL->setLoginStatus(false);
    removeConnection();
    MODEL->setCurrentScreenID(AppEnums::E_SCREEN_t::InvalidScreen);
}

void AppEngine::sendDeliveryNodes()
{
    LOG_DBG << "Current data:" << MODEL->deliveryNodes();
    QStringList listNodes;
    const QStringList deliveryNodes = MODEL->deliveryNodes();
    for (const QString& node : deliveryNodes) {
        if (!node.isEmpty()) {
            listNodes.append(node);
        }
    }
    if (listNodes.isEmpty()) {
        LOG_WRN << "Empty list!";
        return;
    }

    QJsonObject obj;
    QJsonArray nodeArr;
    for (const QString& node : listNodes) {
        QJsonObject nodeObj;
        nodeObj.insert("name", node);
        nodeObj.insert("x", nodeMaps.value(node).x);
        nodeObj.insert("y", nodeMaps.value(node).y);
        nodeObj.insert("z", nodeMaps.value(node).z);
        nodeArr.append(nodeObj);
    }
    obj.insert("nodes", nodeArr);

    LOG_DBG << "Deliver: " << QJsonDocument(obj).toJson(QJsonDocument::Compact);
    m_handler->mqttPublish("robot1/deliver", obj);
}

void AppEngine::handleLoginResponse(const QByteArray &message)
{
    QJsonDocument msgData = QJsonDocument::fromJson(message);
    QJsonObject obj = msgData.object();
    QString response = obj.value("response").toString();
    if (response == "success") {
        MODEL->setLoginStatus(true);
        initConnection();
        MODEL->setCurrentScreenID(AppEnums::E_SCREEN_t::HomeScreen);
    } else {
        MODEL->setLoginStatus(false);
        emit MODEL->notifyLoginFail();
    }
}

void AppEngine::processStateResponse(const QByteArray &message)
{
    QJsonDocument msgData = QJsonDocument::fromJson(message);
    QJsonObject obj = msgData.object();
    int battery = obj.value("battery").toInt();
    int battStt = obj.value("battery_state").toInt();
    int ctrlStt = obj.value("is_controlling_state").toInt();
    int mssnStt = obj.value("is_mission_state").toInt();
    int sensStt = obj.value("sensor_state").toInt();
    QString time = obj.value("time").toString();

    RobotModel::getInstance()->setBattery(battery);
    RobotModel::getInstance()->setBatteryState(battStt);
    RobotModel::getInstance()->setControlState(ctrlStt);
    RobotModel::getInstance()->setMissionState(mssnStt);
    RobotModel::getInstance()->setSensorState(sensStt);
    RobotModel::getInstance()->setTime(time);
}



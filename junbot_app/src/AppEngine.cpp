#include "AppEngine.h"
#include "AppModel.h"
#include "Common.h"
#include "Constants_Def.h"
#include "Screen_Def.h"
#include "AppEnums.h"
#include "QMLHandler.h"
#include "QmlMQTTClient.h"
#include "QMQTTHandler.h"

AppEngine::AppEngine(QObject *parent)
    : QObject(parent)
{
    m_rootContext = m_engine.rootContext();
}

AppEngine::~AppEngine()
{
    // DELETE_DEFS;
    // DELETE_SCR_DEF;
}

void AppEngine::initEngine()
{
    connect(QML_HANDLER, &QMLHandler::notifyQMLEvent, this, &AppEngine::handleEvent);
    qmlRegisterUncreatableType<AppEnums>("QmlCustomItem", 1, 0, "ENUMS", "Uncreatable");

    qmlRegisterType<QmlMqttClient>("MqttClient", 1, 0, "MqttClient");
    qRegisterMetaType<RobotNode>("RobotNode");
    qmlRegisterUncreatableType<QmlMqttSubscription>("MqttClient", 1, 0, "MqttSubscription", QLatin1String("Subscriptions are read-only"));

    // set context properties
    m_rootContext->setContextProperty("QmlHandler",     QML_HANDLER);
    m_rootContext->setContextProperty("CONST",          DEFS);
    m_rootContext->setContextProperty("SCREEN",         SCR_DEF);
    m_rootContext->setContextProperty("AppModel",       MODEL);
    m_rootContext->setContextProperty("QMqttHandler",   QMQTT_HANDLER);

    // init MQTT
    initMQTT();
}

void AppEngine::startApplication()
{
    m_engine.load(SCR_DEF->QML_APP());
}

void AppEngine::handleEvent(int eventID)
{
    switch (eventID) {
    case static_cast<int>(AppEnums::E_SCREEN_t::HomeScreen):
        LOG_DBG <<  "Home Screen";
        MODEL->setCurrentScreenID(AppEnums::HomeScreen);
        initConnection();
        break;
    case static_cast<int>(AppEnums::E_SCREEN_t::ControlScreen):
        LOG_DBG << "Control Screen";
        MODEL->setCurrentScreenID(AppEnums::ControlScreen);
        break;
    case static_cast<int>(AppEnums::E_SCREEN_t::UserScreen):
        LOG_DBG << "User Screen";
        MODEL->setCurrentScreenID(AppEnums::UserScreen);
        break;
    case static_cast<int>(AppEnums::E_EVENT_t::LoginRequest):
        LOG_DBG << "Login Request Screen";
        loginAuthenication();
        break;
    default:
        break;
    }
}

void AppEngine::initMQTT()
{
    m_handler = QMqttHandler::getInstance();
    m_handler->loadMQTTSetting(DEFS->DEVICE_PATH());
    m_handler->initBokerHost(DEFS->BROKER_PATH());

    connect(m_handler, &QMqttHandler::mqttMessageChanged, MODEL, &AppModel::setRobotMess);
    //    connect(m_handler, &QMqttHandler::MQTT_Received, this, &AppModel::setRobotMess);

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
    m_handler->MQTT_Subcrib(m_handler->RobotNodes.at(0));
}

void AppEngine::loginAuthenication()
{
    LOG_DBG << "USER: " << MODEL->userName();
    LOG_DBG << "PASS: " << MODEL->password();

    MODEL->setLoginStatus(true);
}



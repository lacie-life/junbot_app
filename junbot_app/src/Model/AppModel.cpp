#include <QDebug>

#include "AppModel.h"
#include "Constants_Def.h"

AppModel* AppModel::m_instance = nullptr;
QMutex AppModel::m_lock;

AppModel *AppModel::getInstance()
{
    m_lock.lock();
    if(nullptr == m_instance)
    {
        m_instance = new AppModel();
    }
    m_lock.unlock();
    return m_instance;
}

int AppModel::currentScreenID() const
{
    return m_currentScreenID;
}

QString AppModel::robotMess() const
{
    return m_mess;
}

QString AppModel::currentHostName() const
{
    return m_sensor->brokerHosts.at(0);
}

QString AppModel::currentPort() const
{
    return "1883";
}

void AppModel::startHomeScreen()
{
    m_sensor->connectMQTT(m_sensor->brokerHosts.at(0), 1883);
    // m_sensor->MQTT_Subcrib(m_sensor->sensorsNode.at(0));
}

void AppModel::setCurrentScreenID(int currentScreenID)
{
    if (m_currentScreenID == currentScreenID)
        return;

    m_currentScreenID = currentScreenID;
    CONSOLE << "SCREEN ID: " << currentScreenID;
    emit currentScreenIDChanged(m_currentScreenID);
}

void AppModel::slotReceiveEvent(int event)
{
    switch (event) {
    case static_cast<int>(AppEnums::E_SCREEN_t::HomeScreen):
        CONSOLE <<  "Home Screen";
        setCurrentScreenID(AppEnums::HomeScreen);
        startHomeScreen();
        break;
    case static_cast<int>(AppEnums::E_SCREEN_t::ControlScreen):
        CONSOLE << "Control Screen";
        setCurrentScreenID(AppEnums::ControlScreen);
        break;
    case static_cast<int>(AppEnums::E_SCREEN_t::UserScreen):
        CONSOLE << "User Screen";
        setCurrentScreenID(AppEnums::UserScreen);
        break;
    default:
        break;
    }
}

void AppModel::setRobotMess(QString msg)
{
    m_mess = msg;

    emit sensorMessChanged(msg);
}

void AppModel::setCurrentHostName(QString hostName)
{

}

void AppModel::setCurrentPort(QString port)
{

}

AppModel::AppModel(QObject *parent)
    : QObject(parent)
    , m_currentScreenID {static_cast<int>(AppEnums::SearchScreen)}
{
    m_client = QMQTTHandler::getInstance();
    m_client->loadMQTTSetting(DEFS->DEVICE_PATH());
    m_client->initBokerHost(DEFS->BROKER_PATH());

    CONSOLE << m_client->RobotNodes.at(0).topic_data;

    connect(m_client, &QMQTTHandler::mqttMessageChanged, this, &AppModel::setRobotMess);
}

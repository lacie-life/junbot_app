#include "../../hdr/Model/RobotModel.h"

RobotModel *RobotModel::getInstance()
{
    static RobotModel self;
    return &self;
}

int RobotModel::battery() const
{
    return m_battery;
}

void RobotModel::setBattery(int newBattery)
{
    if (m_battery == newBattery)
        return;
    m_battery = newBattery;
    emit batteryChanged();
}

int RobotModel::batteryState() const
{
    return m_batteryState;
}

void RobotModel::setBatteryState(int newBatteryState)
{
    if (m_batteryState == newBatteryState)
        return;
    m_batteryState = newBatteryState;
    emit batteryStateChanged();
}

int RobotModel::controlState() const
{
    return m_controlState;
}

void RobotModel::setControlState(int newControlState)
{
    if (m_controlState == newControlState)
        return;
    m_controlState = newControlState;
    emit controlStateChanged();
}

int RobotModel::missionState() const
{
    return m_missionState;
}

void RobotModel::setMissionState(int newMissionState)
{
    if (m_missionState == newMissionState)
        return;
    m_missionState = newMissionState;
    emit missionStateChanged();
}

int RobotModel::sensorState() const
{
    return m_sensorState;
}

void RobotModel::setSensorState(int newSensorState)
{
    if (m_sensorState == newSensorState)
        return;
    m_sensorState = newSensorState;
    emit sensorStateChanged();
}

QString RobotModel::time() const
{
    return m_time;
}

void RobotModel::setTime(const QString &newTime)
{
    if (m_time == newTime)
        return;
    m_time = newTime;
    emit timeChanged();
}

RobotModel::RobotModel(QObject *parent)
    : QObject { parent }
    , m_battery { 100 }
    , m_batteryState { 0 }
    , m_controlState { 0 }
    , m_missionState { 0 }
    , m_sensorState { 0 }
    , m_time { QLatin1String("1970.1.1 00:00:00") }
{

}

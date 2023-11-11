#include "AppModel.h"
#include "AppEnums.h"
#include "Common.h"

AppModel *AppModel::getInstance()
{
    static AppModel self;
    return &self;
}

AppModel::AppModel(QObject *parent)
    : QObject (parent)
    , m_currentScreenID { static_cast<int>(AppEnums::InvalidScreen) }
    , m_connectionState { static_cast<int>(AppEnums::Disconnected) }
    , m_username { "" }
    , m_password { "" }
    , m_hostname { "localhost" }
    , m_port { 1883 }
{
    m_robotMess = "";
    // Create default available nodes
    m_listNodes.clear();
    const QStringList listNodeNames = nodeMaps.keys();
    for (const QString& nodeName : listNodeNames)
    {
        m_listNodes.append(nodeName);
    }

    // Create default target nodes
    m_deliveryNodes.clear();

    m_deliveryNodes << QString()
                    << QString()
                    << QString();
}

int AppModel::connectionState() const
{
    return m_connectionState;
}

void AppModel::setConnectionState(int newConnectionState)
{
    if (m_connectionState == newConnectionState)
        return;
    m_connectionState = newConnectionState;
    emit connectionStateChanged();
}


int AppModel::currentScreenID() const
{
    return m_currentScreenID;
}

void AppModel::setCurrentScreenID(int newCurrentScreenID)
{
    if (m_currentScreenID == newCurrentScreenID)
        return;
    m_currentScreenID = newCurrentScreenID;
    emit currentScreenIDChanged();
}

bool AppModel::loginStatus() const
{
    return m_loginStatus;
}

void AppModel::setLoginStatus(bool newLoginStatus)
{
    if (m_loginStatus == newLoginStatus)
        return;
    m_loginStatus = newLoginStatus;
    emit loginStatusChanged();
}

QString AppModel::robotMess() const
{
    return m_robotMess;
}

void AppModel::setRobotMess(const QString &newRobotMess)
{
    if (m_robotMess == newRobotMess)
        return;
    m_robotMess = newRobotMess;
    emit robotMessChanged();
}

QString AppModel::password() const
{
    return m_password;
}

void AppModel::setPassword(const QString &newPassword)
{
    if (m_password == newPassword)
        return;
    m_password = newPassword;
    emit passwordChanged();
}

QString AppModel::userName() const
{
    return m_username;
}

void AppModel::setUsername(const QString &newUsername)
{
    if (m_username == newUsername)
        return;
    m_username = newUsername;
    emit usernameChanged();
}

QString AppModel::hostname() const
{
    return m_hostname;
}

void AppModel::setHostname(const QString &newHostname)
{
    if (m_hostname == newHostname)
        return;
    m_hostname = newHostname;
    emit hostnameChanged();
}

int AppModel::port() const
{
    return m_port;
}

void AppModel::setPort(const int &newPort)
{
    if (m_port == newPort)
        return;
    m_port = newPort;
    emit portChanged();
}

QStringList AppModel::deliveryNodes() const
{
    return m_deliveryNodes;
}

void AppModel::setDeliveryNodes(const QStringList &newDeliveryNodes)
{
    if (m_deliveryNodes == newDeliveryNodes)
        return;
    m_deliveryNodes.clear();
    m_deliveryNodes = newDeliveryNodes;
    emit deliveryNodesChanged();
}

QStringList AppModel::listNodes() const
{
    return m_listNodes;
}

void AppModel::setListNodes(const QStringList &newListNodes)
{
    if (m_listNodes == newListNodes)
        return;
    m_listNodes = newListNodes;
    emit listNodesChanged();
}

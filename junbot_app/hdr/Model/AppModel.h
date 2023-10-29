#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QString>
#include <QMutex>
#include <QStringList>

#define MODEL AppModel::getInstance()

class AppModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int          currentScreenID     READ currentScreenID    WRITE setCurrentScreenID    NOTIFY currentScreenIDChanged)
    Q_PROPERTY(QString      robotMess           READ robotMess          WRITE setRobotMess          NOTIFY robotMessChanged)
    Q_PROPERTY(QString      hostname            READ hostname           WRITE setHostname           NOTIFY hostnameChanged)
    Q_PROPERTY(int          port                READ port               WRITE setPort               NOTIFY portChanged)
    Q_PROPERTY(QString      username            READ userName           WRITE setUsername           NOTIFY usernameChanged)
    Q_PROPERTY(QString      password            READ password           WRITE setPassword           NOTIFY passwordChanged)
    Q_PROPERTY(bool         loginStatus         READ loginStatus        WRITE setLoginStatus        NOTIFY loginStatusChanged)
    Q_PROPERTY(int          connectionState     READ connectionState    WRITE setConnectionState    NOTIFY connectionStateChanged)
    Q_PROPERTY(QStringList  listNodes           READ listNodes          WRITE setListNodes          NOTIFY listNodesChanged)
    Q_PROPERTY(QStringList  deliveryNodes       READ deliveryNodes      WRITE setDeliveryNodes      NOTIFY deliveryNodesChanged)

public:
    static AppModel *getInstance();

    QString currentHostName() const;
    QString currentPort() const;

    int connectionState() const;
    void setConnectionState(int newConnectionState);

    int currentScreenID() const;
    void setCurrentScreenID(int newCurrentScreenID);

    bool loginStatus() const;
    void setLoginStatus(bool newLoginStatus);

    QString robotMess() const;
    void setRobotMess(const QString &newRobotMess);

    QString password() const;
    void setPassword(const QString &newPassword);

    QString userName() const;
    void setUsername(const QString &newUsername);

    QString hostname() const;
    void setHostname(const QString &newHostname);

    int port() const;
    void setPort(const int &newPort);

    QStringList deliveryNodes() const;
    void setDeliveryNodes(const QStringList &newDeliveryNodes);

    QStringList listNodes() const;
    void setListNodes(const QStringList &newListNodes);

signals:
    void connectionStateChanged();
    void currentScreenIDChanged();
    void loginStatusChanged();
    void robotMessChanged();
    void passwordChanged();
    void usernameChanged();
    void hostnameChanged();
    void portChanged();
    void deliveryNodesChanged();
    void listNodesChanged();

private:
    AppModel(QObject* parent = nullptr);

    int m_connectionState;
    int m_currentScreenID;
    bool m_loginStatus;
    QString m_robotMess;
    QString m_password;
    QString m_username;
    QString m_hostname;
    int m_port;
    QStringList m_deliveryNodes;
    QStringList m_listNodes;
};

#endif // APPMODEL_H

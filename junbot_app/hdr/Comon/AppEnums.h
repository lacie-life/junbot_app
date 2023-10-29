#ifndef APPENUMS_H
#define APPENUMS_H

#include <QObject>

// TODO: Add target screen
class AppEnums : public QObject
{
    Q_OBJECT
public:

    enum E_SCREEN_t
    {
        HomeScreen = 0,
        ControlScreen,
        UserScreen,
    };
    Q_ENUM(E_SCREEN_t)

    enum E_EVENT_t
    {
        UserClickHome = 0,
        UserClickControl,
        UserClickAccount,
        LoginRequest,
    };
    Q_ENUM(E_EVENT_t)

    enum ConnectState {
        Disconnected,
        Connecting,
        Connected,
    };
    Q_ENUM(ConnectState)

signals:

};

#endif // APPENUMS_H

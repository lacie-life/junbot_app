#ifndef APPENUMS_H
#define APPENUMS_H

#include <QObject>

// TODO: Add target screen
class AppEnums
{
    Q_GADGET
public:
    enum E_SCREEN_t
    {
        HomeScreen,
        ControlScreen,
        UserScreen,
    };
    Q_ENUM(E_SCREEN_t)

    enum E_EVENT_t
    {
        UserClickHome = 0,
        UserClickControl,
        UserClickInfo,
        LoginRequest,
    };
    Q_ENUM(E_EVENT_t)

    enum ConnectState {
        Disconnected,
        Connecting,
        Connected,
    };
    Q_ENUM(ConnectState)

};

#endif // APPENUMS_H

#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QObject>
#include "Constants_Def.h"
#include "QMQTTHandler.h"

// TODO Creat List Sensor Node
// TODO Visual data of sensor node

class HomeScreen : public QObject
{
    Q_OBJECT
    static HomeScreen *m_instance;
public:
    static HomeScreen *getInstance();

    void loadSetting();
    void initHomeScreen();

public:
    QMqttHandler *m_client;

    HomeScreen(QObject* parent = nullptr);
    HomeScreen(const HomeScreen&) = delete;
    void operator =(const HomeScreen&) = delete;
};

#endif // HOMESCREEN_H

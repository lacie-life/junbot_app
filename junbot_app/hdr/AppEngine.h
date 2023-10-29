#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "QMQTTHandler.h"

class AppEngine : public QObject
{
    Q_OBJECT
    QQmlContext *m_rootContext;
    QQmlApplicationEngine m_engine;
    QMqttHandler *m_handler;

public:
    explicit AppEngine(QObject *parent = nullptr);
    ~AppEngine();

    void initEngine();
    void startApplication();

public slots:
    void handleEvent(int eventID);

private:
    void initMQTT();
    void initConnection();
    void loginAuthenication();

signals:

};

#endif // APPENGINE_H

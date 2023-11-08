#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "QMQTTHandler.h"

class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QObject *parent = nullptr);
    ~AppEngine();

    void initEngine();
    void startApplication();

public slots:
    void handleMqttConnected();
    void processMqttMessage(const QByteArray &message, const QString& topicName);
    void handleQmlEvent(int eventID);

private:
    void initMQTT();
    void initConnection();
    void loginAuthenication();
    void sendDeliveryNodes();
    void handleLoginResponse(const QByteArray& message);
    void processStateResponse(const QByteArray& message);

    QQmlContext *m_rootContext;
    QQmlApplicationEngine m_engine;
    QMqttHandler *m_handler;

};

#endif // APPENGINE_H

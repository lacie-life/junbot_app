#include "QmlMQTTClient.h"
#include "Constants_Def.h"

QmlMqttClient::QmlMqttClient(QObject *parent)
    : QMqttClient{parent}
{

}

QmlMqttSubscription *QmlMqttClient::subscribe(const QString &topic)
{
    auto sub = QMqttClient::subscribe(topic, 0);
    if(sub == nullptr){
        CONSOLE << "Fucking Ptr";
    }
    auto result = new QmlMqttSubscription(sub, this);
    return result;
}

QmlMqttSubscription::QmlMqttSubscription(QMqttSubscription *sub, QmlMqttClient *client)
    : m_sub(sub), m_client(client)
{
    connect(sub, &QMqttSubscription::messageReceived, this, &QmlMqttSubscription::handleMessage);
    m_topic = sub->topic();
}

void QmlMqttSubscription::handleMessage(const QMqttMessage &qmsg)
{
    emit messageReceived(qmsg.payload());
}

int QmlMqttClient::publish(const QString &topic, const QString &message, int qos, bool retain)
{
    auto result = QMqttClient::publish(QMqttTopicName(topic), message.toUtf8(), qos, retain);
    return result;
}


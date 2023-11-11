#include "AppEnums.h"
#include "QMQTTHandler.h"
#include "Common.h"
#include "AppModel.h"

QMqttHandler *QMqttHandler::getInstance()
{
    static QMqttHandler self;
    return &self;
}

QMqttHandler::QMqttHandler(QObject* parent)
    : QObject(parent)
{
//    RobotNode node_defalt;
//    node_defalt.current_state_topic = "robot1/state";

//    QJsonObject jobj;

//    jobj["control"] = "test";

//    QJsonDocument jSub = QJsonDocument(jobj);
}


QMqttHandler::~QMqttHandler()
{

}

bool QMqttHandler::loadMQTTSetting(QString path)
{
    return true;
}

int QMqttHandler::initBokerHost(QString path)
{
    broker_path = path;
    return 0;
}

void QMqttHandler::connectMQTT(QString brokerName, qint16 port)
{
    m_client = new QMqttClient(this);

    m_client->setHostname(brokerName);
    m_client->setPort(port);
    m_client->connectToHost();

    connect(m_client, &QMqttClient::connected, this, &QMqttHandler::onMqttConnected);
    connect(m_client, &QMqttClient::disconnected, this, &QMqttHandler::onMqttDisconnected);
    connect(m_client, &QMqttClient::messageReceived, this, &QMqttHandler::onMqttMessageReceived);
}

void QMqttHandler::onMqttConnected()
{
    LOG_DBG << "Connected to MQTT Broker";
    MODEL->setConnectionState(static_cast<int>(AppEnums::Connected));
    mqttSubcribe(m_current_robot_node);
    emit mqttConnected();
}

void QMqttHandler::onMqttDisconnected()
{
    LOG_DBG << "Disconnected to MQTT Broker";
    MODEL->setConnectionState(static_cast<int>(AppEnums::Disconnected));
}

void QMqttHandler::onMqttMessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    LOG_DBG << "Received message: " << message << " from topic: " << topic.name();
    QJsonObject msg = QJsonDocument::fromJson(message).object();
    setMqttMessage(msg);
    emit mqttMessageReceived(message, topic.name());
}

void QMqttHandler::mqttPublish(const RobotNode &node, const QJsonObject &message)
{
    QMqttTopicName topic(node.control_topic);
    QJsonObject jobj;
    jobj["control"] = "test";
    m_client->publish(topic, QJsonDocument(jobj).toJson());
}

void QMqttHandler::mqttPublish(const QString &topic, const QJsonObject &message)
{
    QMqttTopicName mqtt_topic(topic);
    m_client->publish(mqtt_topic, QJsonDocument(message).toJson());
}

void QMqttHandler::pub(QString nod, QString message)
{
    QString topic = "robot1/control";
    QJsonObject jobj;
    jobj[nod] = message;
    m_client->publish(topic, QJsonDocument(jobj).toJson());
}

void QMqttHandler::pubRun(QString Target1, QString Target2, QString Target3)
{
    QString topic = "robot1/control";
    QJsonObject jobj;
    jobj["target1"] = Target1;
    jobj["target2"] = Target2;
    jobj["target3"] = Target3;
    m_client->publish(topic, QJsonDocument(jobj).toJson());
}

void QMqttHandler::mqttSubcribe(RobotNode node)
{
    LOG_DBG << "Subcribe node topic:" << node.current_state_topic;
    QMqttTopicFilter filter(node.current_state_topic);
    m_client->subscribe(filter, 0);
}

void QMqttHandler::mqttSubcribe(const QString &topic)
{
    LOG_DBG << "Subcribe topic:" << topic;
    QMqttSubscription* result = m_client->subscribe(topic);
    if (!result) {
        LOG_ERR << "Cannot subcribe to topic:" << topic;
    }
}

void QMqttHandler::mqttUnsubcribe(RobotNode node)
{
    LOG_DBG << "Unsubcribe node topic:" << node.current_state_topic;
    m_client->unsubscribe(node.current_state_topic);
}

void QMqttHandler::mqttUnsubcribe(const QString &topic)
{
    LOG_DBG << "Unsubcribe topic:" << topic;
    m_client->unsubscribe(topic);
}

void QMqttHandler::setMqttMessage(QJsonObject &msg)
{

}

void QMqttHandler::setCurrentRobotNode(RobotNode node)
{
    
}

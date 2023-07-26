#include "QMLHandler.h"
#include <QDebug>

QMLHandler *QMLHandler::m_instance = nullptr;

QMLHandler *QMLHandler::getInstance()
{
    if (nullptr == m_instance)
    {
        m_instance = new QMLHandler();
    }
    return m_instance;
}

void QMLHandler::qmlSendEvent(int event)
{
    emit notifyQMLEvent(event);
}

void QMLHandler::qmlMessage(QString msg)
{
    qDebug().noquote() << "[QtMsg] " << msg;
}

QMLHandler::QMLHandler()
{

}

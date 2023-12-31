#include "QMLHandler.h"
#include <QDebug>


QMLHandler *QMLHandler::getInstance()
{
    static QMLHandler self;
    return &self;
}

void QMLHandler::qmlSendEvent(int event)
{
    emit notifyQMLEvent(event);
}

void QMLHandler::qmlMessage(QString msg)
{
    qDebug().noquote() << "[QtMsg]" << msg;
}

QMLHandler::QMLHandler()
{

}

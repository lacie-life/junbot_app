#ifndef QMLHANDLER_H
#define QMLHANDLER_H

#include <QObject>
#include <QString>
#include <cstdarg>

#define QML_HANDLER QMLHandler::getInstance()

class QMLHandler : public QObject
{
    Q_OBJECT
    static QMLHandler* m_instance;

public:
    static QMLHandler *getInstance();

public slots:
    void qmlSendEvent(int event);
    void qmlMessage(QString msg);

private:
    QMLHandler();
    QMLHandler(const QMLHandler& _other) = delete;
    void operator =(const QMLHandler& _other) = delete;

signals:
    void notifyQMLEvent(int event);
};

#endif // QMLHANDLER_H

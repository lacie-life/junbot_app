#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "AppEnums.h"
#include "AppModel.h"

class AppEngine : public QObject
{
    Q_OBJECT
    QQmlContext *m_rootContext;
    QQmlApplicationEngine m_engine;

public:
    explicit AppEngine(QObject *parent = nullptr);
    ~AppEngine();

    void initEngine();
    void startApplication();

signals:

};

#endif // APPENGINE_H

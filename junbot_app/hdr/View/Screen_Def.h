#ifndef SCREEN_DEF_H
#define SCREEN_DEF_H

#include <QObject>
#include <QString>
#include <QMutex>
#include <QCoreApplication>
#include <QHash>
#include <QDebug>

#include "AppEnums.h"

#ifndef SCREEN_DEF_MACROS

#define SCREEN_DEF_MACROS

#define DEF_SCREEN(screenName, link) Q_PROPERTY(QString screenName READ screenName CONSTANT) \
    public : QString screenName() const { return QString(link); }

#endif

#ifndef BUILD_DIR

#define BUILD_DIR QCoreApplication::applicationDirPath()

#endif

#define SCR_DEF ScreenDef::getInstance()
#define DELETE_SCR_DEF ScreenDef::DestroyInstance()

class ScreenDef : public QObject
{
    Q_OBJECT
    static ScreenDef* m_instance;
    static QMutex m_lock;

public:
    static ScreenDef* getInstance(){
        m_lock.lock();
        if(nullptr == m_instance)
        {
            m_instance = new ScreenDef();
        }
        m_lock.unlock();
        return m_instance;
    }

    static void DestroyInstance()
    {
        m_lock.lock();
        if(nullptr != m_instance)
        {
            delete m_instance;
        }
        m_instance = nullptr;
        m_lock.unlock();
    }

private:
    ScreenDef(QObject* parent = nullptr)
        : QObject(parent) {}
    ~ScreenDef() {}
    ScreenDef(const ScreenDef&) = delete;
    void operator =(const ScreenDef&) = delete;

    // Define screen
    DEF_SCREEN(QML_PREFIX       , "qrc:/qml/")
    DEF_SCREEN(QML_APP          , QML_PREFIX() + "main.qml")
    DEF_SCREEN(QML_MAIN_SCREEN  , QML_PREFIX() + "MainScreen.qml")
    DEF_SCREEN(QML_LOGIN_SCREEN , QML_PREFIX() + "LoginScreen.qml")
    DEF_SCREEN(QML_TEST         , QML_PREFIX() + "TestScreen.qml")

    // detail screen
    DEF_SCREEN(QML_HOME         , QML_PREFIX() + "Screen/Home/HomeScreen.qml")
    DEF_SCREEN(QML_SEARCH       , QML_PREFIX() + "Screen/Search/SearchScreen.qml")
    DEF_SCREEN(QML_MAP          , QML_PREFIX() + "Screen/Map/MapScreen.qml")
    DEF_SCREEN(QML_CONTROL      , QML_PREFIX() + "Screen/Control/ControlScreen.qml")
    DEF_SCREEN(QML_USER         , QML_PREFIX() + "Screen/User/UserScreen.qml")


};

#endif // SCREEN_DEF_H

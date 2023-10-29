#ifndef SCREEN_DEF_H
#define SCREEN_DEF_H

#include <QObject>
#include <QString>
#include <QMutex>
#include <QCoreApplication>
#include <QHash>

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
public:
    static ScreenDef* getInstance() {
        static ScreenDef self;
        return &self;
    }

private:
    ScreenDef(QObject* parent = nullptr)
        : QObject(parent) {}
    ~ScreenDef() = default;

    // Define screen
    DEF_SCREEN(QML_PREFIX       , "qrc:/qml/")
    DEF_SCREEN(QML_APP          , QML_PREFIX() + "main.qml")
    DEF_SCREEN(QML_MAIN_SCREEN  , QML_PREFIX() + "MainScreen.qml")
    DEF_SCREEN(QML_TEST         , QML_PREFIX() + "TestScreen.qml")

    // detail screen
    DEF_SCREEN(QML_LOGIN_SCREEN , QML_PREFIX() + "Screen/LoginScreen.qml")
    DEF_SCREEN(QML_HOME         , QML_PREFIX() + "Screen/HomeScreen.qml")
    DEF_SCREEN(QML_CONTROL      , QML_PREFIX() + "Screen/ControlScreen.qml")
    DEF_SCREEN(QML_USER         , QML_PREFIX() + "Screen/UserScreen.qml")


};

#endif // SCREEN_DEF_H

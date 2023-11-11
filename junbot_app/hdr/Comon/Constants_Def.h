#ifndef CONSTANTS_DEF_H
#define CONSTANTS_DEF_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QColor>
#include <QMutex>
#include <QCoreApplication>
#include <QDebug>

#ifndef MACRO_DEFINE
#define MACRO_DEFINE

#define DEF_VAR(type, name, value) Q_PROPERTY(type name READ name NOTIFY dataUpdate) \
    public: type name() { return value; }

#define DEF_CONST(type, name, value) Q_PROPERTY(type name READ name CONSTANT) \
    public: type name() const { return value; }

#endif

class Constants_Def : public QObject
{
    Q_OBJECT
public:
    static Constants_Def* getInstance() {
        static Constants_Def self;
        return &self;
    }

signals:
    void dataUpdated();

private:
    explicit Constants_Def(QObject* parent = nullptr)
        : QObject{ parent }
    { }
    ~Constants_Def() = default;

    // define property

    /******************************************* RESOURCE ************************************************/

    // QML
    DEF_CONST(QString, QML_HOME , "qrc:/qml/Screen/Home/HomeScreen.qml")

    // IMAGES
    DEF_CONST(QString, IMAGE_PREFIX , "qrc:/res/")
    DEF_CONST(QString, HOME_IMG     , "joystick.png")
    DEF_CONST(QString, CONTROL_IMG  , "navigation.png")
    DEF_CONST(QString, INFO_IMG     , "info.png")
    DEF_CONST(QString, USER_IMG     , "user_128x128.png")
    DEF_CONST(QString, PASSWD_IMG   , "padlock_128x128.png")

    // Config
    DEF_CONST(QString, BROKER_PATH, ":/config/config/broker.json")
    DEF_CONST(QString, DEVICE_PATH, ":/config/config/devices.json")


    /********************************************** GENERAL **********************************************/
    DEF_CONST(int,      MAX_WIDTH,          480)
    DEF_CONST(int,      MAX_HEIGHT,         854)
    DEF_CONST(int,      MENU_BAR_WIDTH,     30)

    // constant color
    DEF_CONST(QColor,   COLOR_SHADOW,       "#3F3F3F")
    DEF_CONST(QColor,   COLOR_FRAME_BG,     "#CACACA")
    DEF_CONST(QColor,   COLOR_DEFAULT_TEXT, "#2A2A2A")
    DEF_CONST(QString,  COLOR_INVISIBLE,    "transparent")

};


#endif // CONSTANTS_DEF_H

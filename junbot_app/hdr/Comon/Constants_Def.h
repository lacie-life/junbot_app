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

#define DEFS Constants_Def::instance()
#define DELETE_DEFS Constants_Def::DestroyInstance()

#ifndef BUILD_DIR

#define BUILD_DIR QCoreApplication::applicationDirPath()

#endif

class Constants_Def : public QObject
{
    Q_OBJECT

signals:
    void dataUpdated();

public:
    static Constants_Def* instance() {
        static Constants_Def self;
        return &self;
    }

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
    DEF_CONST(QString, SEARCH_IMG   , "search.svg"  )
    DEF_CONST(QString, HOME_IMG     , "joystick.png"    )
    DEF_CONST(QString, CONTROL_IMG  , "navigation.png" )
    DEF_CONST(QString, MAP_IMG      , "map.svg"     )
    DEF_CONST(QString, USER_IMG     , "info.png"    )
    DEF_CONST(QString, MAP_MARKER   , IMAGE_PREFIX() + "mapmarker.png")

    // Config
    DEF_CONST(QString, BROKER_PATH, ":/config/config/broker.json")
    DEF_CONST(QString, DEVICE_PATH, ":/config/config/devices.json")


    /********************************************** GENERAL **********************************************/
    DEF_CONST(int, MAX_WIDTH        , 720   )
    DEF_CONST(int, MAX_HEIGHT       , 1080  )
    DEF_CONST(int, MENU_BAR_WIDTH   , 80    )

    DEF_CONST(QString   , EMPTY_STRING , ""    )

    // search screen constant
    DEF_CONST(int, INPUT_BOX_WIDTH      , 1100  )
    DEF_CONST(int, INPUT_BOX_HEIGHT     , 60    )
    DEF_CONST(int, INPUT_BOX_TOP_MARGIN , 15    )

    // constant color
    DEF_CONST(QColor, COLOR_SWITCH_OFF      , "#ADADAD")
    DEF_CONST(QColor, COLOR_SWITCH_ON       , "#00CCD9")
    DEF_CONST(QColor, COLOR_SWITCH_BTN_NOOD , "#F0F0F0")
    DEF_CONST(QColor, COLOR_BORDER_DARK     , "#777777")

    DEF_CONST(QColor, COLOR_MENU_BAR        , "#00AF2A")
    DEF_CONST(QColor, COLOR_MENU_BAR_FOCUS  , "#DDDDDD")
    DEF_CONST(QColor, COLOR_BACK_GROUND     , COLOR_MENU_BAR_FOCUS())

    DEF_CONST(QString, COLOR_INVISIBLE      , "transparent")

    // QChart define
    DEF_CONST(int, CHART_DRAW_OFFSET, 10)
};


#endif // CONSTANTS_DEF_H

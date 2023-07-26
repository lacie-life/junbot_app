#ifndef CONSTANTS_DEF_H
#define CONSTANTS_DEF_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QColor>
#include <QMutex>
#include <QCoreApplication>

#ifndef MACRO_DEFINE
#define MACRO_DEFINE

#define CONSOLE qDebug() << "[" << __FUNCTION__ << "] "
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

    static Constants_Def* m_instance;
    static QMutex m_lock;

signals:
    void dataUpdated();

public:
    static Constants_Def* instance()
    {
        m_lock.lock();
        if (nullptr == m_instance)
        {
            m_instance = new Constants_Def();
        }
        m_lock.unlock();
        return m_instance;
    }

    static void DestroyInstance()
    {
        m_lock.lock();
        if (nullptr != m_instance)
        {
            delete m_instance;
        }
        m_instance = nullptr;
        m_lock.unlock();
    }

private:
    explicit Constants_Def(QObject* parent = nullptr)
        : QObject{ parent }
    { }
    ~Constants_Def() {}
    Constants_Def(const Constants_Def&) = delete;
    bool operator= (const Constants_Def&) = delete ;


    // define property

    /******************************************* RESOURCE ************************************************/

    // QML

    // IMAGES
    DEF_CONST(QString, IMAGE_FOLDER , "file:" + BUILD_DIR + "/share/res/")
    DEF_CONST(QString, SEARCH_IMG   , "search.svg"  )
    DEF_CONST(QString, HOME_IMG     , "home.svg"    )
    DEF_CONST(QString, CONTROL_IMG  , "control.svg" )
    DEF_CONST(QString, MAP_IMG      , "map.svg"     )
    DEF_CONST(QString, USER_IMG     , "user.svg"    )
    DEF_CONST(QString, MAP_MARKER   , IMAGE_FOLDER() + "mapmarker.png")

    // Config

    DEF_CONST(QString, BROKER_PATH, ":/config/config/broker.json")
    DEF_CONST(QString, DEVICE_PATH, ":/config/config/devices.json")


    /********************************************** GENERAL **********************************************/
    DEF_CONST(int, MAX_WIDTH        , 1280  )
    DEF_CONST(int, MAX_HEIGHT       , 680   )
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

import QtQuick 2.0
import QtQuick.Window 2.12
import "Component"
import "Component/Common"
import QmlCustomItem 1.0

Item {

    id: root

    QMenuBar {
        id: menuBar
        width: CONST.MENU_BAR_WIDTH
        height: root.width
        anchors.left: root.left
        anchors.top: root.top
    }

    QRec {
        id: mainScreen
        width: root.width - CONST.MENU_BAR_WIDTH
        height: root.height
        anchors.top: root.top
        anchors.left: menuBar.right

        color: CONST.COLOR_INVISIBLE
    }

    Loader {
        id: screenLoader
        visible: true
        property int screenID: AppModel.currentScreenID
        anchors.fill: mainScreen
        onScreenIDChanged: source = getScreenUrl(screenID)
        Component.onCompleted: {
            source = getScreenUrl(screenID)
        }
    }

    function getScreenUrl(id){
        QmlHandler.qmlMessage("getScreenUrl " + id)
        QmlHandler.qmlMessage("getScreenUrl " + ENUMS.HomeScreen + " " + ENUMS.SearchScreen)
        switch(id){
        case ENUMS.HomeScreen:
            QmlHandler.qmlMessage("Home Screen");
            QmlHandler.qmlMessage(SCREEN.QML_HOME);
            return SCREEN.QML_HOME
        case ENUMS.ControlScreen:
            QmlHandler.qmlMessage("Control Screen");
            return SCREEN.QML_CONTROL
        case ENUMS.UserScreen:
            QmlHandler.qmlMessage("User Screen");
            return SCREEN.QML_USER
        default:
            return ""
        }
    }

}

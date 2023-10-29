import QtQuick 2.0
import QtQuick.Window 2.12
import "Component"
import "Component/Common"
import QmlCustomItem 1.0

Item {
    id: root
    MenuBar {
        id: menuBar
        width: 720
        height: 80
        anchors.left: root.left
        anchors.bottom: root.bottom
    }

    QRec {
        id: mainScreen
        width: 720
        height: 1080 - 80
        anchors.top: root.top
        anchors.bottom: menuBar.top
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

    function getScreenUrl(id) {
        switch (id) {
        case ENUMS.HomeScreen:
            QmlHandler.qmlMessage("Home Screen");
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


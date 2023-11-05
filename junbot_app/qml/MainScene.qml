import QtQuick 2.0
import QtQuick.Window 2.12
import QmlCustomItem 1.0
import "Component"
import "Component/Common"

Item {
    id: root
    MenuBar {
        id: menuBar
        width: 720
        height: 80
        anchors.left: root.left
        anchors.bottom: root.bottom
    }

    Loader {
        id: screenLoader
        visible: true
        width: 720
        height: 1000
        anchors.top: root.top
        anchors.bottom: menuBar.top
        source: getScreenUrl(AppModel.currentScreenID)
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


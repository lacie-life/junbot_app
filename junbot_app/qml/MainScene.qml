import QtQuick 2.0
import QtQuick.Window 2.12
import QmlCustomItem 1.0
import "Component"
import "Component/Common"

Item {
    id: root
    MenuBar {
        id: menuBar
        width: parent.width
        height: parent.height * 0.1
        anchors.left: root.left
        anchors.bottom: root.bottom
    }

    Loader {
        id: screenLoader
        visible: true
        width: parent.width
        height: parent.height * 0.9
        anchors.top: root.top
        anchors.bottom: menuBar.top
        source: getScreenUrl(AppModel.currentScreenID)

    }

    function getScreenUrl(id) {
        switch (id) {
        case ENUMS.HomeScreen:
            return SCREEN.QML_HOME
        case ENUMS.ControlScreen:
            return SCREEN.QML_CONTROL
        case ENUMS.InfoScreen:
            return SCREEN.QML_INFO
        default:
            return ""
        }
    }
}


import QtQuick 2.0
import QmlCustomItem 1.0

QRec {
    id: root
    color: "grey"
    width: 720
    height: 80

    QtObject {
        id: self
        property var icons: [CONST.HOME_IMG, CONST.CONTROL_IMG, CONST.INFO_IMG]
        property var eventIDs: [ENUMS.UserClickHome, ENUMS.UserClickControl, ENUMS.UserClickInfo]

        function getIcon(index, isDark) {
            return (isDark ? "dark/" : "light/") + icons[index]
        }
    }

    QRec {
        id: tab_indexer
        color: "#FF3434"
        width: root.width / 3
        height: root.height
        anchors {
            left: parent.left
            leftMargin: AppModel.currentScreenID * width
        }
        Behavior on anchors.leftMargin {
            NumberAnimation {
                duration: 150
                easing.type: Easing.OutBack
            }
        }
    }

    Row {
        id: layout
        anchors.fill: parent
        spacing: 6
        Repeater {
            model: 3
            anchors.fill: parent
            delegate: delegate_item
        }
    }

    Component {
        id: delegate_item
        MenuItem {
            width: root.width / 3
            height: root.height
            sizeImage: height * (AppModel.currentScreenID === index ? 0.7 : 0.5)
            sourceImage: self.getIcon(index, AppModel.currentScreenID === index)
            onClicked: {
                AppModel.currentScreenID = index
                QmlHandler.qmlSendEvent(self.eventIDs[index])
            }
        }
    }
}

import QtQuick 2.0
import QtGraphicalEffects 1.15

Item {
    id: root
    property var margins: []
    property double borderWidth: 1
    property double borderRadius: 0
    property color borderColor: "transparent"
    property color backgroundColor: CONST.COLOR_FRAME_BG

    Rectangle {
        id: frame
        anchors.fill: parent
        border.color: root.borderColor
        border.width: root.borderWidth
        radius: root.borderRadius
        color: root.backgroundColor
        smooth: true
    }

    DropShadow {
        anchors.fill: frame
        horizontalOffset: 4
        verticalOffset: 4
        radius: 5
        color: CONST.COLOR_SHADOW
        source: frame
    }

    Component.onCompleted: {
        if (root.margins.length == 1) {
            frame.anchors.margins = root.margins[0]
        } else if (margins.length == 2) {
            frame.anchors.topMargin = root.margins[0]
            frame.anchors.rightMargin = root.margins[1]
            frame.anchors.bottomMargin = root.margins[0]
            frame.anchors.leftMargin = root.margins[1]
        } else if (margins.length == 4) {
            frame.anchors.topMargin = root.margins[0]
            frame.anchors.rightMargin = root.margins[1]
            frame.anchors.bottomMargin = root.margins[2]
            frame.anchors.leftMargin = root.margins[3]
        } else {
            QmlHandler.qmlMessage("Wrong margins format...")
        }
    }
}

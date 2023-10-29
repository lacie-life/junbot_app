import QtQuick 2.0
import QtGraphicalEffects 1.15

Item {
    id: root
    property var    margins: [ 0 ]
    property double borderWidth: 1
    property double borderRadius: 0
    property color  borderColor: "transparent"
    property color  backgroundColor: CONST.COLOR_FRAME_BG
    property bool   drawShadow: true

    readonly property double topMargin: self.topMargin
    readonly property double rightMargin: self.rightMargin
    readonly property double bottomMargin: self.bottomMargin
    readonly property double leftMargin: self.leftMargin

    QtObject {
        id: self
        property double topMargin: 0
        property double rightMargin: 0
        property double bottomMargin: 0
        property double leftMargin: 0

        function updateMargins() {
            if (root.margins.length == 1) {
                topMargin = root.margins[0]
                rightMargin = root.margins[0]
                bottomMargin = root.margins[0]
                leftMargin = root.margins[0]

            } else if (margins.length == 2) {
                topMargin = root.margins[0]
                rightMargin = root.margins[1]
                bottomMargin = root.margins[0]
                leftMargin = root.margins[1]

            } else if (margins.length == 4) {
                topMargin = root.margins[0]
                rightMargin = root.margins[1]
                bottomMargin = root.margins[2]
                leftMargin = root.margins[3]

            } else {
                topMargin = 0
                rightMargin = 0
                bottomMargin = 0
                leftMargin = 0
                QmlHandler.qmlMessage("Wrong margins format...")
            }
        }
    }

    Rectangle {
        id: frame
        anchors {
            fill: parent
            topMargin: self.topMargin
            rightMargin: self.rightMargin
            leftMargin: self.leftMargin
            bottomMargin: self.bottomMargin
        }

        border.color: root.borderColor
        border.width: root.borderWidth
        radius: root.borderRadius
        color: root.backgroundColor
        smooth: true
    }

    DropShadow {
        visible: root.drawShadow
        anchors.fill: frame
        horizontalOffset: 4
        verticalOffset: 4
        radius: 5
        color: CONST.COLOR_SHADOW
        source: frame
    }

    onMarginsChanged: {
        self.updateMargins()
    }

    Component.onCompleted: {
        self.updateMargins()
    }
}

import QtQuick 2.15
import QtGraphicalEffects 1.15
import "../../js/func.js" as Func

Item {
    id: root
    property string iconName: "cancel"
    property double radius: 50
    property string backgroundColor: "#eaeaea"
    property string hoveredColor: Func.darker(backgroundColor, 20)
    property string pressedColor: Func.darker(hoveredColor, 20)
    property bool rotateOnPress: false

    width: 100
    height: 100

    signal clicked()
    signal pressed()
    signal released()

    QtObject {
        id: self
        property bool isHovered: false
        property bool isPressed: false
        property double sizeScale: 0.5
    }

    Rectangle {
        id: bg
        anchors.fill: parent
        radius: root.radius
        color: self.isPressed ? root.pressedColor : self.isHovered ? root.hoveredColor : root.backgroundColor
    }
    DropShadow {
        anchors.fill: bg
        horizontalOffset: 4
        verticalOffset: 4
        radius: 5
        color: "#5f5f5f"
        source: bg
    }

    Image {
        id: icon
        anchors.centerIn: parent
        sourceSize: Qt.size(root.width * self.sizeScale, root.height * self.sizeScale)
        source: "qrc:/res/" + root.iconName + ".png"
    }

//    RotationAnimator {
//        id: rotation_animator
//        target: icon
//        from: 0
//        to: 180
//        duration: 670
//        running: false
//        easing.type: Easing.OutBack
//    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onClicked: root.clicked()
        onEntered: self.isHovered = true
        onExited: self.isHovered = false

        onPressed: {
            self.isPressed = true
            root.pressed()
//            if (root.rotateOnPress) {
//                rotation_animator.start()
//            }
        }

        onReleased: {
            self.isPressed = false
            root.released()
        }
    }


}

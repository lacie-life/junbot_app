import QtQuick 2.0

Rectangle {
    id: root
    property string iconName: "cancel"
    radius: 10
    color: self.isPressed ? "#828282" : self.isHovered ? "#c6c6c6" : "transparent"

    signal clicked()
    signal pressed()
    signal released()

    width: 125
    height: 125

    QtObject {
        id: self
        property bool isHovered: false
        property bool isPressed: false
        property double sizeScale: 0.8
    }

    Image {
        anchors.centerIn: parent
        sourceSize: Qt.size(root.width * self.sizeScale, root.height * self.sizeScale)
        source: "qrc:/res/" + root.iconName + ".png"
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onClicked: root.clicked()
        onEntered: self.isHovered = true
        onExited: self.isHovered = false

        onPressed: {
            self.isPressed = true
            root.pressed()
        }

        onReleased: {
            self.isPressed = false
            root.released()
        }
    }
}

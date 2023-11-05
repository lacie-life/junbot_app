import QtQuick 2.0

Rectangle {
    id: root
    width: 400
    height: 60
    radius: height / 2
    color: self.isPressed ? "#cacaca" : "#fff"

    signal requestLogin()

    QtObject {
        id: self
        property bool isPressed: false
    }

    Text {
        anchors.centerIn: parent
        anchors.verticalCenterOffset: 3
        color: "#000"
        text: "Login"
        font.pixelSize: 30
        font.bold: true
    }

    MouseArea {
        anchors.fill: parent
        onPressed: self.isPressed = true
        onReleased: self.isPressed = false
        onClicked: {
            root.requestLogin()
        }
    }
}

import QtQuick 2.0
import QtGraphicalEffects 1.12

Rectangle {
    id: root
    property bool isPassword: false
    readonly property string textData: text_input.text.trim()

    width: 400
    height: 60
    radius: height / 2
    color: "transparent"
    border.width: 2
    border.color: "#cacaca"

    Image {
        id: ico
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -2
        anchors.right: parent.right
        anchors.rightMargin: 15

        source: root.isPassword ? "qrc:/res/padlock_32.png"
                                : "qrc:/res/user_32.png"
        smooth: true
        visible: false
    }

    ColorOverlay {
        anchors.fill: ico
        source: ico
        color: "#cacaca"
    }

    TextInput {
        id: text_input
        anchors {
            verticalCenter: parent.verticalCenter
            verticalCenterOffset: 2
            left: parent.left
            leftMargin: 30
        }
        width: 300
        height: 60

        horizontalAlignment: TextEdit.AlignLeft
        verticalAlignment: TextEdit.AlignVCenter
        font.pixelSize: 23
        font.family: "Helvetica"
        renderType: TextEdit.QtRendering
        color: "#fff"

        echoMode: root.isPassword ? TextInput.Password
                                  : TextInput.Normal
    }

    Text {
        id: place_holder

        anchors {
            verticalCenter: text_input.verticalCenter
            left: text_input.left
        }

        height: parent.height
        horizontalAlignment: TextEdit.AlignLeft
        verticalAlignment: TextEdit.AlignVCenter

        font.pixelSize: 23
        font.family: "Helvetica"
        color: "#cacaca"
        renderType: TextEdit.QtRendering

        text: root.isPassword ? "Password" : "Username"
        visible: text_input.length === 0 && !text_input.focus
    }
}

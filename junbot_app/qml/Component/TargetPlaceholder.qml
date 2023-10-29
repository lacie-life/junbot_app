import QtQuick 2.0
import "Common"

Frame {
    id: root
    property string currentData: ""
    readonly property bool occupied: currentData !== ""

    signal clicked()

    borderRadius: 10
    width: 200
    height: 100
    backgroundColor: occupied ? "#63D9FF" : CONST.COLOR_FRAME_BG
    drawShadow: occupied
    borderColor: occupied ? "transparent" : "#A8A8A8"
    borderWidth: 2

    QText {
        id: label
        anchors.centerIn: parent
        anchors.verticalCenterOffset: (root.bottomMargin - root.topMargin) / 2 + (root.occupied ? 5 : 2)
        anchors.horizontalCenterOffset: (root.leftMargin - root.rightMargin) / 2
        font.bold: true
        font.pixelSize: 30
        color: root.occupied ? CONST.COLOR_DEFAULT_TEXT : "#A8A8A8"
        text: root.occupied ? root.currentData : "+"
    }

    MouseArea {
        id: ma
        enabled: root.occupied
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
}

import QtQuick 2.0
import "../Common"

Frame {
    id: root
    property string nodeData: ""
    property bool activated: false

    signal clicked()

    borderRadius: 10
    width: 200
    height: 100
    backgroundColor: activated ? "#63D9FF" : "#FF6363"

    QText {
        id: label
        anchors.centerIn: parent
        anchors.verticalCenterOffset: (root.topMargin - root.bottomMargin) / 2 + 2
        anchors.horizontalCenterOffset: (root.leftMargin - root.rightMargin) / 2
        font.bold: true
        font.pixelSize: 30
        color: CONST.COLOR_DEFAULT_TEXT
        text: root.nodeData
    }

    MouseArea {
        id: ma
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
}

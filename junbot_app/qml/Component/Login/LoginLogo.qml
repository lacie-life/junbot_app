import QtQuick 2.0

Item {
    id: root
    Rectangle {
        id: bg1
        anchors.fill: parent
        radius: 20
        color: "#fff"
    }

    Rectangle {
        id: bg2
        anchors.bottom: parent.bottom
        width: parent.width
        height: parent.height / 2
        color: bg1.color
    }

    Image {
        id: vmc_logo
        anchors.centerIn: parent
        sourceSize.width: parent.height * 400 / 148
        sourceSize.height: parent.height * 0.8
        source: "qrc:/res/VMC_Logo.png"
    }
}

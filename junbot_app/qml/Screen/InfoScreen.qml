import QtQuick 2.12
import QmlCustomItem 1.0
import "../Component/Common"
import "../Component/Login"

Item {
    id: root
    width: 1080
    height: 720

    Rectangle {
        id: logo
        width: 150
        height: 150
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top

        Image {
            id: logo_image
            anchors.centerIn: parent
            width: 150
            height: 150
            source: "qrc:/res/icon_bot.png"
        }
    }

    QText {
        id: name
        anchors {
            top: logo.bottom
            topMargin: 28
            horizontalCenter: parent.horizontalCenter
        }
        font.bold: true
        text: qsTr("Robot VDR-01 of Viettel Manufacturing")
    }
}

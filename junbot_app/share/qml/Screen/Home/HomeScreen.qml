import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1
import QtQuick.Layouts 1.1

import MqttClient 1.0
import "../../Component/Common"
import "../../Component"
import QmlCustomItem 1.0

QRec {
    id: root

    Button{
        id: stopButton
        height: 150
        width: 150
        anchors.centerIn: parent

        Image{
            id: stop
            anchors.fill: parent
            source: "qrc:/res/res/stop.png"
        }
    }

    Button{
        id: leftButton
        height: 150
        width: 150
        anchors.right: stopButton.left
        anchors.rightMargin: 15
        anchors.top: stopButton.top

        Image{
            id: left
            anchors.fill: parent
            source: "qrc:/res/res/left.png"
        }
    }

    Button{
        id: rightButton
        height: 150
        width: 150
        anchors.left: stopButton.right
        anchors.leftMargin: 15
        anchors.top: stopButton.top

        Image{
            id: right
            anchors.fill: parent
            source: "qrc:/res/res/right.png"
        }
    }

    Button{
        id: upButton
        height: 150
        width: 150
        anchors.bottom: stopButton.top
        anchors.bottomMargin: 15
        anchors.left: stopButton.left

        Image{
            id: up
            anchors.fill: parent
            source: "qrc:/res/res/up.png"
        }
    }

    Button{
        id: downButton
        height: 150
        width: 150
        anchors.top: stopButton.bottom
        anchors.topMargin: 15
        anchors.left: stopButton.left

        Image{
            id: down
            anchors.fill: parent
            source: "qrc:/res/res/down.png"

        }
    }
}

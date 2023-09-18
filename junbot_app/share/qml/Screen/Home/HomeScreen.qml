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

    Rectangle{
        id: test
        height: 150
        width: 150
        color: "blue"

        MouseArea{
            height: test.height
            width: test.width
            onPressed: {
                parent.color = "green"
            }
            onReleased: {
                parent.color = "blue"
            }
        }
    }

    Rectangle{
        id: stopButton
        height: 150
        width: 150
        anchors.centerIn: parent

        Image{
            id: stop
            anchors.fill: parent
            source: "qrc:/res/res/stop.png"
        }

        MouseArea{
            width: stopButton.width
            height: stopButton.width
        }
    }

    Rectangle{
        id: leftButton
        height: 150
        width: 150
        anchors.right: stopButton.left
        anchors.rightMargin: 20
        anchors.top: stopButton.top

        Image{
            id: left
            anchors.fill: parent
            source: "qrc:/res/res/left.png"
        }

        MouseArea{
            width: leftButton.width
            height: leftButton.width
        }
    }

    Rectangle{
        id: rightButton
        height: 150
        width: 150
        anchors.left: stopButton.right
        anchors.leftMargin: 20
        anchors.top: stopButton.top

        Image{
            id: right
            anchors.fill: parent
            source: "qrc:/res/res/right.png"
        }

        MouseArea{
            width: rightButton.width
            height: rightButton.height
        }
    }

    Rectangle{
        id: upButton
        height: 150
        width: 150
        anchors.bottom: stopButton.top
        anchors.bottomMargin: 20
        anchors.left: stopButton.left

        Image{
            id: up
            anchors.fill: parent
            source: "qrc:/res/res/up.png"
        }

        MouseArea{
            width: upButton.width
            height: upButton.height
        }
    }

    Rectangle{
        id: downButton
        height: 150
        width: 150
        anchors.top: stopButton.bottom
        anchors.topMargin: 20
        anchors.left: stopButton.left

        Image{
            id: down
            anchors.fill: parent
            source: "qrc:/res/res/down.png"

            MouseArea{
                width: downButton.width
                height: downButton.height
            }
        }
    }
}


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
        id: mainScreen
        height: root.height
        width: root.width

        Image{
            id: bg
            anchors.fill: parent
            source: "qrc:/res/res/white_bg.jpg"
        }

        Item{
            id: stopButton
            height: 150
            width: 150
            anchors.centerIn: parent

            Image{
                id: stop
                anchors.fill: parent
                source: "qrc:/res/res/stop1.png"
            }

            MouseArea{
                width: stopButton.width
                height: stopButton.width

                onClicked: {
                    QmlHandler.qmlMessage("stop")
                    QMqttHandler.pub("control", "stop")
                }

                onPressed:{
                    stop.source = "qrc:/res/res/stop2.png"
                }

                onReleased: {
                    stop.source = "qrc:/res/res/stop1.png"
                }
            }
        }

        Item{
            id: leftButton
            height: 150
            width: 150
            anchors.right: stopButton.left
            anchors.rightMargin: 20
            anchors.top: stopButton.top

            Image{
                id: left
                anchors.fill: parent
                source: "qrc:/res/res/left1.png"
            }

            MouseArea{
                width: leftButton.width
                height: leftButton.width

                onClicked: {
                    QmlHandler.qmlMessage("turn left")
                    QMqttHandler.pub("control", "turn left")
                }

                onPressed:{
                    left.source = "qrc:/res/res/left2.png"
                }

                onReleased: {
                    left.source = "qrc:/res/res/left1.png"
                }
            }
        }

        Item{
            id: rightButton
            height: 150
            width: 150
            anchors.left: stopButton.right
            anchors.leftMargin: 20
            anchors.top: stopButton.top

            Image{
                id: right
                anchors.fill: parent
                source: "qrc:/res/res/right1.png"
            }

            MouseArea{
                width: rightButton.width
                height: rightButton.height

                onClicked: {
                    QmlHandler.qmlMessage("turn right")
                    QMqttHandler.pub("control", "turn right")
                }

                onPressed:{
                    right.source = "qrc:/res/res/right2.png"
                }

                onReleased: {
                    right.source = "qrc:/res/res/right1.png"
                }
            }
        }

        Item{
            id: upButton
            height: 150
            width: 150
            anchors.bottom: stopButton.top
            anchors.bottomMargin: 20
            anchors.left: stopButton.left

            Image{
                id: up
                anchors.fill: parent
                source: "qrc:/res/res/up1.png"
            }

            MouseArea{
                width: upButton.width
                height: upButton.height

                onClicked: {
                    QmlHandler.qmlMessage("forward")
                    QMqttHandler.pub("control", "forward")
                }

                onPressed:{
                    up.source = "qrc:/res/res/up2.png"
                }

                onReleased: {
                    up.source = "qrc:/res/res/up1.png"
                }
            }
        }

        Item{
            id: downButton
            height: 150
            width: 150
            anchors.top: stopButton.bottom
            anchors.topMargin: 20
            anchors.left: stopButton.left

            Image{
                id: down
                anchors.fill: parent
                source: "qrc:/res/res/down1.png"

                MouseArea{
                    width: downButton.width
                    height: downButton.height

                    onClicked: {
                        QmlHandler.qmlMessage("back")
                        QMqttHandler.pub("control", "back")
                    }

                    onPressed:{
                        down.source = "qrc:/res/res/down2.png"
                    }

                    onReleased: {
                        down.source = "qrc:/res/res/down1.png"
                    }
                }
            }
        }
    }
}

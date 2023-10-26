import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

import MqttClient 1.0
import QmlCustomItem 1.0
import "../../Component/Common"
import "../../Component"

Rectangle {
    id: root

    Image {
        id: bg
        anchors.fill: parent
        source: "qrc:/res/white_bg.jpg"
    }

    Item {
        id: log_area
        height: 600
        width: root.width
        Rectangle {
            anchors.fill: parent
            anchors.margins: 10
            border.color: "black"
        }

        Text {
            anchors.centerIn: parent
            text: qsTr("should config to show log inside this box")
        }
    }

    Item {
        id: controller_area
        height: 400
        width: root.width
        anchors.top: log_area.bottom

        ControllerButton {
            id: stop_button
            anchors.centerIn: parent
            iconName: "cancel"
            onClicked: {
                QmlHandler.qmlMessage("stop")
                QMqttHandler.pub("control", "stop")
            }
        }
        ControllerButton {
            id: left_button
            anchors {
                verticalCenter: stop_button.verticalCenter
                right: stop_button.left
            }
            iconName: "left"
            onClicked: {
                QmlHandler.qmlMessage("turn left")
                QMqttHandler.pub("control", "turn left")
            }
        }
        ControllerButton {
            id: right_button
            anchors {
                verticalCenter: stop_button.verticalCenter
                left: stop_button.right
            }
            iconName: "right"
            onClicked: {
                QmlHandler.qmlMessage("turn right")
                QMqttHandler.pub("control", "turn right")
            }
        }
        ControllerButton {
            id: up_button
            anchors {
                horizontalCenter: stop_button.horizontalCenter
                bottom: stop_button.top
            }
            iconName: "up"
            onClicked: {
                QmlHandler.qmlMessage("forward")
                QMqttHandler.pub("control", "forward")
            }
        }
        ControllerButton {
            id: down_button
            anchors {
                horizontalCenter: stop_button.horizontalCenter
                top: stop_button.bottom
            }
            iconName: "down"
            onClicked: {
                QmlHandler.qmlMessage("back")
                QMqttHandler.pub("control", "back")
            }
        }
    }
}

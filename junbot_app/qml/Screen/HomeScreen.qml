    import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

import MqttClient 1.0
import QmlCustomItem 1.0
import "../Component/Home"
import "../Component/Common"
import "../../js/func.js" as Func

Rectangle {
    id: root

    Frame {
        id: connection_indicator
        width: parent.width
        height: parent.height * 0.05
        borderRadius: 10
        margins: [ 10, 10, 5, 10 ]

        QText {
            id: connection_label
            anchors.centerIn: parent
            anchors.verticalCenterOffset: 5

            font.bold: true
            text: {
                switch (AppModel.connectionState) {
                case ENUMS.Disconnected:
                    return "Disconnected."
                case ENUMS.Connecting:
                    return "Connecting..."
                case ENUMS.Connected:
                    return "Connected."
                default:
                    return "Unavailable."
                }
            }
        }
    }

    Frame {
        id: state_area
        anchors.top: connection_indicator.bottom
        width: parent.width
        height: parent.height * 0.6
        borderRadius: 10
        margins: [ 10, 10, 5, 10 ]
        Column {
            width: parent.width - 60
            height: parent.height - 50
            anchors.centerIn: parent
            spacing: 5
            QText {
                text: qsTr("<b>Battery Percent</b>: %1%").arg(RobotModel.battery)
            }
            QText {
                text: qsTr("<b>Battery State</b>: %1").arg(RobotModel.batteryState)
            }
            QText {
                text: qsTr("<b>Control State</b>: %1").arg(RobotModel.controlState)
            }
            QText {
                text: qsTr("<b>Mission State</b>: %1").arg(RobotModel.missionState)
            }
            QText {
                text: qsTr("<b>Sensor State</b>: %1").arg(RobotModel.sensorState)
            }
            QText {
                text: qsTr("<b>Current time</b>: %1").arg(RobotModel.time)
            }
        }
    }

    Item {
        id: controll_area
        anchors.top: state_area.bottom
        width: parent.width
        height: parent.height - connection_indicator.height - state_area.height

        Item {
            id: left
            anchors.left: parent.left
            width: parent.width / 2
            height: parent.height
            ControllerButton {
                id: left_button
                anchors.centerIn: parent
                anchors.horizontalCenterOffset: -width
                iconName: "left"
                onClicked: {
                    QmlHandler.qmlMessage("turn left")
                    QMqttHandler.pub("control", "turn left")
                }
            }
            ControllerButton {
                id: right_button
                anchors.centerIn: parent
                anchors.horizontalCenterOffset: width
                iconName: "right"
                onClicked: {
                    QmlHandler.qmlMessage("turn right")
                    QMqttHandler.pub("control", "turn right")
                }
            }
            ControllerButton {
                id: up_button
                anchors.centerIn: parent
                anchors.verticalCenterOffset: -height * 5/6
                iconName: "up"
                onClicked: {
                    QmlHandler.qmlMessage("forward")
                    QMqttHandler.pub("control", "forward")
                }
            }
            ControllerButton {
                id: down_button
                anchors.centerIn: parent
                anchors.verticalCenterOffset: height * 5/6
                iconName: "down"
                onClicked: {
                    QmlHandler.qmlMessage("back")
                    QMqttHandler.pub("control", "back")
                }
            }
        }

        Item {
            id: right
            anchors.right: parent.right
            width: parent.width / 2
            height: parent.height
            ControllerButton {
                id: stop_button
                anchors.centerIn: parent
                width: 200
                height: 200
                radius: 50
                rotateOnPress: true
                backgroundColor: "#FE5757"
                hoveredColor: "#FF4040"
                pressedColor: "#FF2626"
                iconName: "cancel"
                onClicked: {
                    QmlHandler.qmlMessage("stop")
                    QMqttHandler.pub("control", "stop")
                }
            }
        }
    }
}

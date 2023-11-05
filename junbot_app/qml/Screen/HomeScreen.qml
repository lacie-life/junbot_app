    import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

import MqttClient 1.0
import QmlCustomItem 1.0
import "../Component"
import "../Component/Common"
import "../../js/func.js" as Func

Rectangle {
    id: root

    Frame {
        id: connection_indicator
        height: 70
        width: parent.width
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
        id: log_area
        anchors.top: connection_indicator.bottom
        height: 600
        width: parent.width
        borderRadius: 10
        margins: [ 10, 10, 5, 10 ]

        // TODO: make a logger to show log in this area
    }

    Item {
        id: controll_area
        anchors.top: log_area.bottom
        width: parent.width
        height: parent.height - connection_indicator.height - log_area.height

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

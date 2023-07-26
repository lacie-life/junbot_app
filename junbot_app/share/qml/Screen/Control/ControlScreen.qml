import QtQuick 2.12
import QtQuick.Controls 2.15

import "../../Component/Common"
import MqttClient 1.0

QRec {

    id: controlScreen
    color: CONST.COLOR_BACK_GROUND

    MqttClient {
        id: client
        clientId: "kms_Dashboard"
        hostname: AppModel.currentHostName()
        port: qsTr(AppModel.currentPort())
        cleanSession: true
    }

    QText {
        id: pump 
        anchors.top: controlScreen.top
        anchors.topMargin: 5
        anchors.left: controlScreen.left
        anchors.leftMargin: 10
        text: qsTr("Pump Control")
        color: "black"
    }

    property bool on: true

    Switch {
        id: control
        anchors.top: controlScreen.top
        anchors.topMargin: 50
        anchors.left: controlScreen.left
        anchors.leftMargin: 50

        text: qsTr("Switch")

        indicator: Rectangle {
            implicitWidth: 48
            implicitHeight: 26
            x: control.leftPadding
            y: parent.height / 2 - height / 2
            radius: 13
            color: control.checked ? "#17a81a" : "#ffffff"
            border.color: control.checked ? "#17a81a" : "#cccccc"

            Rectangle {
                x: control.checked ? parent.width - width : 0
                width: 26
                height: 26
                radius: width
                color: control.down ? "#cccccc" : "#ffffff"
                border.color: control.checked ? (control.down ? "#17a81a" : "#21be2b") : "#999999"
            }
        }

        contentItem: Text {
            text: control.text
            font: control.font
            opacity: enabled ? 1.0 : 0.3
            color: control.down ? "#17a81a" : "#21be2b"
            verticalAlignment: Text.AlignVCenter
            leftPadding: control.indicator.width + control.spacing
        }

        onClicked: {
            client.connectToHost();
            on = !on;
            QmlHandler.qmlMessage("State changed");
            if (on == false) {
                QmlHandler.qmlMessage("ON");
                client.publish(qsTr("pump/001"), "ON",2,false);
            }
            else{
                QmlHandler.qmlMessage("OFF");
                client.publish(qsTr("pump/001"), "OFF",2,false);
            }
        }
    }
}

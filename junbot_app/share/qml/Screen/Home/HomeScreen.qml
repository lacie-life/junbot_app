import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1
import QtQuick.Layouts 1.1

import MqttClient 1.0
import "../../Component/Common"
import "../../Component"
import QmlCustomItem 1.0

//QRec {
//    visible: true
//    id: root
//    color: CONST.COLOR_BACK_GROUND

//    Text {
//        id: sensorMessage
//        anchors.centerIn: root
//        text: qsTr(AppModel.sensorMess)
//    }
//}

QRec {
    id: root

    Rectangle{
        id:mainLoginScreen
        width: root.width
        height: root.height
        color: "gray"

        Rectangle{
            id: mainLoginArea
            width: mainLoginScreen.width/1.5
            height: mainLoginScreen.height/2
            anchors.centerIn: parent
            color: "white"

            Rectangle{
                id: loginLogo
                width: 120
                height: 120
                anchors.top: parent.top
                anchors.topMargin: 75
                anchors.horizontalCenter: mainLoginArea.horizontalCenter

                color: "red"
            }

            Rectangle{
                id:userTextField
                width: 300
                height: 50
                anchors.top: loginLogo.bottom
                anchors.topMargin: 50
                anchors.horizontalCenter: mainLoginArea.horizontalCenter

                color: "blue"
            }

            Rectangle{
                id: passwordTextField
                width: 300
                height: 50
                anchors.top: userTextField.bottom
                anchors.topMargin: 25
                anchors.horizontalCenter: mainLoginArea.horizontalCenter

                color: "blue"
            }

            Rectangle{
                id: buttonLogin
                width: 175
                height: 70
                anchors.top: passwordTextField.bottom
                anchors.topMargin: 40
                anchors.horizontalCenter: mainLoginArea.horizontalCenter

                color: "green"
            }
        }
    }
}

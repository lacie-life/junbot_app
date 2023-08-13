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
    id: homeScreen
    color: "white"

    Button{
        id: button_test
        text: "click me"

        onClicked: {
            QMqttHandler.pub()
        }
    }
}

import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1
import QtQuick.Layouts 1.1

import "../../Component/Common"
import MqttClient 1.0

QRec {
    id: root
    QMenuButton {
        id: menuButton
        anchors.top: root.top
        anchors.left: root.left
    }
}


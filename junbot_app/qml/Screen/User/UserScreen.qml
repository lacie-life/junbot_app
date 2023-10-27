import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1
import QtQuick.Layouts 1.1
import "../../Component/Common"

QRec{
    id: root

    Rectangle {
        width: 480
        height: 320
        Rectangle {
            x: 30; y: 30
            width: 300; height: 240
            color: "lightsteelblue"

            MouseArea {
                anchors.fill: parent
                drag.target: parent;
                drag.axis: "XAxis"
                drag.minimumX: 30
                drag.maximumX: 150
                drag.filterChildren: true

                Rectangle {
                    color: "yellow"
                    x: 50; y : 50
                    width: 100; height: 100
                    MouseArea {
                        anchors.fill: parent
                        onClicked: console.log("Clicked")
                    }
                }
            }
        }
    }
}

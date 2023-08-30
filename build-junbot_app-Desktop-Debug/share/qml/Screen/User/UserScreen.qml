import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1
import QtQuick.Layouts 1.1
import "../../Component/Common"

QRec{
    id: root

    Rectangle{
    width: 150; height: 200; color: "gray";

        ListModel{
            id: nameModel
            ListElement {name: "Alice"}
            ListElement {name: "Bob"}
            ListElement {name: "Jane"}
            ListElement {name: "Victor"}
            ListElement {name: "Wendy"}
            ListElement {name: "Alice1"}
            ListElement {name: "Bob1"}
            ListElement {name: "Jane1"}
            ListElement {name: "Victor1"}
            ListElement {name: "Wendy1"}
            ListElement {name: "Alice2"}
            ListElement {name: "Bob2"}
            ListElement {name: "Jane2"}
            ListElement {name: "Victor2"}
            ListElement {name: "Wendy2"}
            ListElement {name: "Alice3"}
            ListElement {name: "Bob3"}
            ListElement {name: "Jane3"}
            ListElement {name: "Victor3"}
            ListElement {name: "Wendy3"}
        }

        Component{
            id:nameDelegate
            Rectangle{
                color: lv.currentIndex === index ? "white" : "yellow"
                implicitHeight: txt.implicitHeight
                implicitWidth: txt.implicitWidth

                Text {
                    id: txt
                    text: model.name;
                    font.pixelSize: 32
                    Component.onCompleted: console.log("Welcome", model.index, model.name)
                    Component.onDestruction: console.log("Bye", model.index, model.name)
                    MouseArea{
                        anchors.fill: parent
                        onClicked: lv.currentIndex = index
                    }
                }
            }
        }

        ListView{
            id: lv
            anchors.fill: parent
            model: nameModel
            delegate: nameDelegate
            clip: true
            onCurrentIndexChanged: console.log(currentIndex)
        }
    }
}

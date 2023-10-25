import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1
import QtQuick.Layouts 1.1

import "../../Component/Common"
import MqttClient 1.0

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

        Rectangle{
            id: delivery_box1
            anchors.left: mainScreen.left
            anchors.top: mainScreen.top
            width: root.width
            height: 200
            anchors.topMargin: 20
            border.width: 2
            border.color: "black"

            Rectangle{
                id: target_1
                anchors.verticalCenter: delivery_box1.verticalCenter
                anchors.left: delivery_box1.left
                anchors.leftMargin: 30
                width: 200
                height: 80
                color:  "#f1f1f1"
                border.width: 1
                radius: 10
                Text{
                    id:tx_1
                    anchors.centerIn: parent
                    text: "+"
                    font.pixelSize: 24
                }
            }
            Text{
                id: target1_text
                text: "Target 1"
                font.pixelSize: 24
                anchors.top: target_1.bottom
                anchors.left: target_1.left
                anchors.leftMargin: 52
            }

            Rectangle{
                id: target_2
                anchors.centerIn: parent
                width: 200
                height: 80
                color:  "#f1f1f1"
                border.width: 1
                radius: 10
                Text{
                    id:tx_2
                    anchors.centerIn: parent
                    text: "+"
                    font.pixelSize: 24
                }
            }
            Text{
                id: target2_text
                text: "Target 2"
                font.pixelSize: 24
                anchors.top: target_2.bottom
                anchors.left: target_2.left
                anchors.leftMargin: 52
            }

            Rectangle{
                id: target_3
                anchors.verticalCenter: delivery_box1.verticalCenter
                anchors.right: delivery_box1.right
                anchors.rightMargin: 30
                width: 200
                height: 80
                color:  "#f1f1f1"
                border.width: 1
                radius: 10
                Text{
                    id:tx_3
                    anchors.centerIn: parent
                    text: "+"
                    font.pixelSize: 24
                }
            }
            Text{
                id: target3_text
                text: "Target 3"
                font.pixelSize: 24
                anchors.top: target_3.bottom
                anchors.left: target_3.left
                anchors.leftMargin: 52
            }
        }

        Rectangle{
            id: delivery_text1
            anchors.left: delivery_box1.left
            anchors.top: root.top
            anchors.topMargin: 40
            anchors.leftMargin: 20
            width: 238
            height: 38
            Text{
                font.pointSize: 24
                text: " Delivery Target"
            }
        }

        Rectangle{
            id: delivery_box2
            anchors.top: delivery_box1.bottom
            anchors.topMargin: 60
            width: root.width
            height: 580
            border.width: 2
            border.color: "black"

            Component.onCompleted: {
                var buttons = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L'];
                var i;
                for(i = 0; i < buttons.length; i++){
                    gridview.model.append({
                                              myText: buttons[i]
                                          });
                }

            }

            GridView{
                id: gridview
                anchors{
                    top: parent.top
                    bottom: parent.bottom
                    left: parent.left
                    right:parent.right
                    leftMargin: 20
                    rightMargin: 20
                    topMargin: 20
                }

                cellWidth: width/3
                cellHeight: height/4

                model: ListModel {}

                delegate: Rectangle{
                    id: deleItem
                    width: gridview.cellWidth * 0.9
                    height: gridview.cellHeight * 0.9
                    color: "#FF244B"
                    Text{
                        id:deleText
                        text: myText
                        anchors.centerIn: parent
                        font.pointSize: 50
                        color: "white"
                    }
                    MouseArea{
                        width: deleItem.width
                        height: deleItem.height
                        onClicked: {
                            console.log(deleText.text)
                            if(tx_1.text == "+"){
                                tx_1.text = deleText.text
                            }else if(tx_2.text == "+"){
                                tx_2.text = deleText.text
                            }else if(tx_3.text == "+"){
                                tx_3.text = deleText.text
                            }
                        }
                        onPressed: {
                            deleItem.color = "#AD1530"
                            deleText.color = "#C5C3C3"
                        }
                        onReleased: {
                            deleItem.color = "#FF244B"
                            deleText.color = "white"
                        }
                    }
                }

                clip: true
            }
        }

        Rectangle{
            id: remove_button
            anchors.left: mainScreen.left
            anchors.leftMargin: 90
            anchors.top: delivery_box2.bottom
            anchors.topMargin: 35
            width: 240
            height: 60
            color:  "#f1f1f1"
            border.width: 1
            radius: 15

            Text {
                id: remove_text
                anchors.centerIn: parent
                text: "Remove Target"
                font.pixelSize: 24
            }

            MouseArea{
                width: remove_button.width
                height: remove_button.height
                onClicked: {
                    tx_1.text = "+"
                    tx_2.text = "+"
                    tx_3.text = "+"
                }
                onPressed: {
                    remove_button.color = "#B4B2B2"
                }
                onReleased: {
                    remove_button.color = "#f1f1f1"
                }
            }
        }

        Rectangle{
            id: run_button
            anchors.right: mainScreen.right
            anchors.rightMargin: 90
            anchors.top: delivery_box2.bottom
            anchors.topMargin: 35
            width: 240
            height: 60
            color:  "#f1f1f1"
            border.width: 1
            radius: 15

            Text {
                id: run_text
                anchors.centerIn: parent
                text: "Run"
                font.pixelSize: 24
            }

            MouseArea{
                width: run_button.width
                height: run_button.height
                onClicked: {
                    QMqttHandler.pubRun(tx_1.text, tx_2.text, tx_3.text)
                }
                onPressed: {
                    run_button.color = "#B4B2B2"
                }
                onReleased: {
                    run_button.color = "#f1f1f1"
                }
            }
        }
    }

    //    Rectangle{
    //        id: delivery_box2
    //        anchors.top: delivery_box1.bottom
    //        anchors.topMargin: 60
    //        width: root.width
    //        height: 600
    //        border.width: 2
    //        border.color: "black"

    //        Component.onCompleted: {
    //            var colores = ['orange', 'red', 'green', 'blue', 'cyan', 'brown'];
    //            var ix;
    //            var jx;
    //            for(jx = 0; jx < 3; ++jx){
    //                for(ix = 0; ix < colores.length; ++ix){
    //                    gridview.model.append({
    //                        myColor: colores[ix]
    //                    });
    //                }
    //            }
    //        }

    //        GridView{
    //            id: gridview
    //            anchors{
    //                top: parent.top
    //                bottom: parent.bottom
    //                left: parent.left
    //                right:parent.right
    //                leftMargin: 20
    //                rightMargin: 20
    //                topMargin: 20
    //                bottomMargin: 150
    //            }

    //            cellWidth: width/3
    //            cellHeight: height/3

    //            model: ListModel {}

    //            delegate: Rectangle{
    //            width: gridview.cellWidth * 0.9
    //            height: gridview.cellHeight * 0.9
    //            color: myColor
    //            }
    //        }
    //    }

    //  Rectangle{
    //    y: 250
    //    width: 740
    //    height: 500
    //        Component.onCompleted: {
    //            var colores = ['orange', 'red', 'green', 'blue', 'cyan', 'brown'];
    //            var ix;
    //            var jx;
    //            for(jx = 0; jx < 3; ++jx){
    //                for(ix = 0; ix < colores.length; ++ix){
    //                    gridview.model.append({
    //                        myColor: colores[ix]
    //                    });
    //                }
    //            }
    //        }

    //        GridView{
    //            id: gridview
    //            anchors{
    //                top: parent.top
    //                bottom: parent.bottom
    //                left: parent.left
    //                right:parent.right
    //                leftMargin: 20
    //                rightMargin: 20
    //            }

    //            cellWidth: width/3
    //            cellHeight: height/3

    //            model: ListModel {}

    //            delegate: Rectangle{
    //            width: gridview.cellWidth * 0.9
    //            height: gridview.cellHeight * 0.9
    //            color: myColor
    //            }
    //        }
    //    }
}


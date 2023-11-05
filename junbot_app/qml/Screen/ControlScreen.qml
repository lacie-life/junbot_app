import QtQuick 2.12
import QmlCustomItem 1.0
import "../../js/func.js" as Func
import "../Component/Controller"
import "../Component/Common"

Item {
    id: root
    Frame {
        id: delivery_target
        width: parent.width
        height: 250
        borderRadius: 10
        margins: [ 10 ]

        QText {
            id: name
            anchors {
                top: parent.top
                topMargin: 28
                horizontalCenter: parent.horizontalCenter
            }
            font.bold: true
            text: qsTr("Delivery Targets")
        }

        Rectangle {
            anchors.top: parent.top
            anchors.topMargin: 60
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width * 0.9
            height: 1
            color: "#5e5e5e"
        }

        TargetPlaceholderList {
            id: target_list
            anchors.centerIn: parent
            anchors.verticalCenterOffset: 25
            onRequestRemoveItem: {
                for (var i = 0; i < grid.count; i++) {
                    if (grid.itemAtIndex(i).nodeData === item) {
                        grid.itemAtIndex(i).activated = false
                    }
                }
            }
        }
    }


    Frame {
        id: node_grid
        anchors.top: delivery_target.bottom
        width: parent.width
        height: 600
        borderRadius: 10
        margins: [ 10 ]

        GridView {
            id: grid
            readonly property int cols: Math.floor(width / cellWidth)
            anchors.fill: parent
            anchors.margins: 10
            model: AppModel.listNodes
            cellWidth: width / 3
            cellHeight: height / 4
            interactive: false
            delegate: NodeButton {
                width: grid.cellWidth
                height: grid.cellHeight
                nodeData: modelData
                margins: [ 10 ]
                onClicked: {
                    if (!activated) {
                        activated = target_list.addTarget(nodeData)
                    } else {
                        activated = !target_list.removeItem(nodeData)
                    }
                }
            }
        }

        function updateGridActivation() {
            for (let i = 0; i < AppModel.listNodes.length; i++) {
                let data = grid.itemAtIndex(i).nodeData
                for (let j = 0; j < AppModel.deliveryNodes.length; j++) {
                    if (AppModel.deliveryNodes[j] !== "" && AppModel.deliveryNodes[j] === data) {
                        grid.itemAtIndex(i).activated = true
                    }
                }
            }
        }


        Connections {
            target: target_list
            function onRequestRemoveItem(item) {
                for (var idx = 0; idx < grid.count; idx++) {
                    // calculate index_x, index_y from
                    let x_index = idx % grid.cols
                    let y_index = Math.floor(idx / grid.cols)

                    // calculate center position of item with index_x and index_y
                    let x = (x_index * grid.cellWidth) + grid.cellWidth / 2
                    let y = (y_index * grid.cellHeight) + grid.cellHeight / 2

                    // get item have that center and check its data
                    if (grid.itemAt(x, y).nodeData === item) {
                        grid.itemAt(x, y).activated = false
                    }
                }
            }
        }
    }

    Frame {
        id: start_button
        width: parent.width
        height: parent.height - delivery_target.height - node_grid.height
        anchors.top: node_grid.bottom
        margins: [10, 10, 20, 10]
        borderRadius: 10
        backgroundColor: pressed ? pressedColor : "#63FFA8"

        property bool pressed: false
        property string pressedColor: Func.darker("#63FFA8", 20)

        QText {
            anchors.centerIn: parent
            anchors.verticalCenterOffset: (parent.bottomMargin - parent.topMargin) / 2
            font.pixelSize: 50
            font.bold: true
            text: "START"
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.pressed = true
            onReleased: parent.pressed = false
            onClicked: {
                QMqttHandler.pubRun(AppModel.deliveryNodes[0], AppModel.deliveryNodes[1], AppModel.deliveryNodes[2]);
//                console.warn("Do something in CPP, use the MODEL->deliveryNodes() to get list targets:", AppModel.deliveryNodes)
                QmlHandler.qmlSendEvent(ENUMS.SendDeliveryNodes)
            }
        }
    }

    Component.onCompleted: {
        target_list.initFromModel()
        node_grid.updateGridActivation()
    }
}

import QtQuick 2.0
import "Common"

Item {
    id: root
    property double sizeImage: height
    property string sourceImage: ""

    // Signals Declare
    signal clicked()

    QImage
    {
        id: imageID
        width: root.sizeImage
        height: root.sizeImage
        anchors.centerIn: root
        imgName: root.sourceImage
    }

    MouseArea
    {
        anchors.fill: root
        onClicked: root.clicked()
    }

    Behavior on sizeImage {
        NumberAnimation {
            duration: 150
            easing.type: Easing.OutQuad
        }
    }
}

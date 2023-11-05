import QtQuick 2.0
import QtGraphicalEffects 1.12

Item {
    id: root
    width: 1080
    height: 720

    Image {
        id: img
        anchors.fill: parent
        source: "qrc:/res/red_bg.jpg"
    }

    ShaderEffectSource {
        id: shader
        anchors.centerIn: parent
        width: 500
        height: 600
        sourceItem: img
        sourceRect: Qt.rect(x, y, width, height)
    }

    FastBlur {
        id: blur_layer
        visible: false
        anchors.fill: shader
        source: shader
        radius: 80
    }

    Rectangle {
        id: mask
        visible: false
        anchors.fill: shader
        radius: 20
    }

    OpacityMask {
        anchors.fill: mask
        source: blur_layer
        maskSource: mask
    }
}

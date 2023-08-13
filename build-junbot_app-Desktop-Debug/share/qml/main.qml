import QtQuick 2.12
import QtQuick.Window 2.12

import QmlCustomItem 1.0

Window
{
    id: root
    width: CONST.MAX_WIDTH
    height: CONST.MAX_HEIGHT
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width

    visible: true

    Loader
    {
        anchors.fill: parent
        source: SCREEN.QML_MAIN_SCREEN
    }

}

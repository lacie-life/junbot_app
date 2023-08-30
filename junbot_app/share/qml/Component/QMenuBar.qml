import QtQuick 2.0
import QmlCustomItem 1.0
import "Common"

QRec{
    id: root
    color: CONST.COLOR_MENU_BAR
    width: 720
    height: 80

    ListView
    {
        id: listScreen
        model: 5
        width: root.width
        height: root.height

        currentIndex: AppModel.currentScreenID
        interactive: contentHeight > height

        orientation: ListView.Horizontal

        delegate: Item {

            id: delegateItem

            width: parent.width/5
            height: parent.height

            QButton {
                id: icon

                allowImage: true
                anchors.fill: parent
                color: listScreen.currentIndex === index ? CONST.COLOR_MENU_BAR_FOCUS : CONST.COLOR_INVISIBLE

                sizeImage: height * 0.5
                sourceImage: getIcon(index, listScreen.currentIndex === index)

                onClicked: {
                    listScreen.currentIndex = index
                    QmlHandler.qmlSendEvent(getEventID(index))
                }
            }
        }

    }

    function getIcon(index, isDark) {
        var colorFolder = "light/"

        if (isDark) {
            colorFolder = "dark/"
        }

        switch(index) {
        case 0:
            return colorFolder + CONST.HOME_IMG
        case 1:
            return colorFolder + CONST.CONTROL_IMG
        case 2:
            return colorFolder + CONST.USER_IMG
        default:
            return ""
        }
    }

    function getEventID(index) {
        switch(index) {
        case 0:
            return ENUMS.UserClickHome
        case 1:
            return ENUMS.UserClickControl
        case 2:
            return ENUMS.UserClickAccount
        default:
            return ""
        }
    }
}




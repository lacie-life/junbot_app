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
//    width: parent.width
//    height: parent.height
    visible: true
    visibility: Window.FullScreen

    Item {
        id: scene_loader
        width: parent.width * 2
        height: parent.height
        x: AppModel.loginStatus ? -CONST.MAX_WIDTH : 0

        LoginScene {
            id: login_scene
            width: CONST.MAX_WIDTH
            height: CONST.MAX_HEIGHT
            anchors.left: parent.left
            visible: scene_loader.x !== -CONST.MAX_WIDTH
        }

        MainScene {
            id: main_scene
            width: CONST.MAX_WIDTH
            height: CONST.MAX_HEIGHT
            anchors.left: login_scene.right
            visible: scene_loader.x !== 0
        }

        Behavior on x {
            NumberAnimation {
                duration: 200
                easing.type: Easing.InOutCirc
            }
        }
    }
}

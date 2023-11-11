import QtQuick 2.12
import QtQuick.Window 2.12
import QmlCustomItem 1.0

Window
{
    id: root
    visible: true
    visibility: Window.FullScreen

    Item {
        id: scene_loader
        width: Window.width * 2
        height: Window.height
        x: AppModel.loginStatus ? -Window.width : 0

        LoginScene {
            id: login_scene
            width: Window.width
            height: Window.height
            anchors.left: parent.left
            visible: scene_loader.x !== -Window.width
        }

        MainScene {
            id: main_scene
            width: Window.width
            height: Window.height
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

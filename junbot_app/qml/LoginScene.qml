import QtQuick 2.0
import QmlCustomItem 1.0
import QtGraphicalEffects 1.12
import "Component/Login"
import "Component"

Item {
    id: root
    LoginBackground {
        id: bg
        anchors.fill: parent
    }

    Rectangle {
        id: login_form
        anchors.centerIn: parent
        width: 500
        height: 600
        border.width: 2
        border.color: "#cacaca"
        color: "transparent"
        radius: 20

        LoginLogo {
            id: vmc_logo
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
        }

        FontLoader {
            id: vt_font
            source: "qrc:/fonts/FSMagistral/FSMagistral-Bold.ttf"
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: vmc_logo.bottom
            anchors.topMargin: 7
            font {
                pixelSize: 45
                family: vt_font.name
            }
            color: "#fafafa"
            text: "Login"
        }

        LoginInput {
            id: username_field
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: vmc_logo.bottom
                topMargin: 100
            }
        }

        LoginInput {
            id: passwrd_field
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: username_field.bottom
                topMargin: 20
            }
            isPassword: true
        }

        LoginButton {
            id: login_button
            anchors {
                top: passwrd_field.bottom
                topMargin: 60
                horizontalCenter: parent.horizontalCenter
            }
            onRequestLogin: {
                hide_message_timer.stop()
                shake_animation.stop()
                login_message.visible = false

                AppModel.username = username_field.textData
                AppModel.password = passwrd_field.textData
                QmlHandler.qmlSendEvent(ENUMS.LoginRequest)
            }
        }

        Text {
            id: login_message
            anchors.horizontalCenter: login_button.horizontalCenter
            anchors.bottom: login_button.top
            anchors.bottomMargin: 20
            font {
                pixelSize: 17
                styleName: "Italic"
            }

            text: "Login failed!"
            visible: false
            color: "white"
        }
    }

    SequentialAnimation {
        id: shake_animation
        NumberAnimation { target: login_form; property: "anchors.horizontalCenterOffset"; to: 10;  duration: 50; easing.type: Easing.InOutQuad }
        NumberAnimation { target: login_form; property: "anchors.horizontalCenterOffset"; to: -10; duration: 50; easing.type: Easing.InOutQuad }
        NumberAnimation { target: login_form; property: "anchors.horizontalCenterOffset"; to: 10;  duration: 50; easing.type: Easing.InOutQuad }
        NumberAnimation { target: login_form; property: "anchors.horizontalCenterOffset"; to: -10; duration: 50; easing.type: Easing.InOutQuad }
        NumberAnimation { target: login_form; property: "anchors.horizontalCenterOffset"; to: 0;   duration: 50; easing.type: Easing.InOutQuad }
    }

    Timer {
        id: hide_message_timer
        interval: 1000
        onTriggered: login_message.visible = false
    }

    Connections {
        target: AppModel
        function onNotifyLoginFail() {
            login_message.visible = true
            hide_message_timer.start()
            shake_animation.start()
        }
    }
}

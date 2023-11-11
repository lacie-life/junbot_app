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
        width: parent.width * 50/72
        height: parent.height * 15/27
        border.width: 2
        border.color: "#cacaca"
        color: "transparent"
        radius: 20

        LoginLogo {
            id: vmc_logo
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            width: parent.width
            height: parent.height / 4
        }

        FontLoader {
            id: vt_font
            source: "qrc:/fonts/FSMagistral/FSMagistral-Bold.ttf"
        }

        Text {
            id: login_label
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: vmc_logo.bottom
            anchors.topMargin: parent.height * 0.02
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
                top: login_label.bottom
                topMargin: parent.height * 0.03
            }
            width: parent.width * 4 / 5
            height: parent.height * 1 / 6
        }

        LoginInput {
            id: passwrd_field
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: username_field.bottom
                topMargin: parent.height * 0.03
            }
            width: parent.width * 4 / 5
            height: parent.height * 1 / 6
            isPassword: true
        }

        LoginButton {
            id: login_button
            anchors {
                top: passwrd_field.bottom
                topMargin: parent.height * 0.03
                horizontalCenter: parent.horizontalCenter
            }
            width: parent.width * 4 / 5
            height: parent.height * 1 / 6
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

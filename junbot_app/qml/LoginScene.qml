import QtQuick 2.0
import QmlCustomItem 1.0
import QtGraphicalEffects 1.12
import "Component/Login"
import "Component"

Item {
    id: root
    width: 1080
    height: 720

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
                AppModel.username = username_field.textData
                AppModel.password = passwrd_field.textData
                QmlHandler.qmlSendEvent(ENUMS.LoginRequest)
            }
        }
    }
}

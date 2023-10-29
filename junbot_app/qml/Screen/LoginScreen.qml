import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QmlCustomItem 1.0
import "../Component/Common"

Item {
    id: root
    Rectangle {
        id: mainLoginScreen
        width: root.width
        height: root.height

        Image {
            id: bg
            anchors.fill: parent
            source: "qrc:/res/red_bg.jpg"
        }

        Rectangle {
            id: mainLoginArea
            width: mainLoginScreen.width/1.4
            height: mainLoginScreen.height/2
            anchors.centerIn: parent
            radius: 35
            color: "white"

            Rectangle {
                id: loginLogo
                width: 300
                height: 125
                anchors.top: parent.top
                anchors.topMargin: 60
                anchors.horizontalCenter: mainLoginArea.horizontalCenter
                Image {
                    id: logoViettel
                    anchors.fill: parent
                    source: "qrc:/res/VMC_Logo.png"
                }
            }

            Rectangle {
                id: inputArea
                height: 120
                anchors.left: parent.left
                anchors.leftMargin: 50
                anchors.right: parent.right
                anchors.rightMargin: 50
                anchors.top: loginLogo.bottom
                anchors.topMargin: 50

                TextField {
                    id: userName
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    height: parent.height/2
                    horizontalAlignment: Text.AlignLeft
                    font.pointSize: 15
                    placeholderText: "User Name"
                }

                TextField {
                    id: userPassword
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: userName.bottom
                    anchors.topMargin: 20
                    height: parent.height/2
                    horizontalAlignment: Text.AlignLeft
                    font.pointSize: 15
                    echoMode: TextInput.Password
                    placeholderText: "Password"
                }
            }

            Rectangle {
                id: buttonLogin
                anchors.left: parent.left
                anchors.leftMargin: 165
                anchors.right: parent.right
                anchors.rightMargin: 165
                anchors.top: inputArea.bottom
                anchors.topMargin: 50
                height: 60
                color: "red"
                border.color: "white"
                border.width: 2
                radius: 25
                Text {
                    id: name
                    anchors.left: parent.left
                    anchors.leftMargin: 76
                    anchors.top: parent.top
                    anchors.topMargin: 15
                    text: "OK"
                    color: "white"
                    font.pointSize: 18
                    font.bold: true
                }
                MouseArea {
                    width: buttonLogin.width
                    height: buttonLogin.height
                    onClicked: {
                        AppModel.userName = userName.text
                        AppModel.pass = userPassword.text
                        QmlHandler.qmlMessage("LOL")
                        QmlHandler.qmlSendEvent(ENUMS.LoginRequest)
                    }
                }
            }
        }
    }
}

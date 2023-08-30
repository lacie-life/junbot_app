import QtQuick 2.0
import QtQuick.Controls 1
import QtQuick.Layouts 1.0
import QmlCustomItem 1.0
import "Component/Common"


Item {

    id: root

    Rectangle{
        id: mainLoginScreen
        width: root.width
        height: root.height
        color: "gray"

        Rectangle{
            id: mainLoginArea
            width: mainLoginScreen.width/2
            height: mainLoginScreen.height/1.5
            anchors.centerIn: parent
            color: "white"

            Rectangle{
                id: loginLogo
                width: 120
                height: 120
                anchors.top: parent.top
                anchors.topMargin: 75
                anchors.horizontalCenter: mainLoginArea.horizontalCenter
                color: "blue"
            }

            Rectangle{
                id: inputArea
                height: 100
                anchors.left: parent.left
                anchors.leftMargin: 75
                anchors.right: parent.right
                anchors.rightMargin: 75
                anchors.top: loginLogo.bottom
                anchors.topMargin: 25

                TextField{
                    id: userName
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    height: parent.height/2
                    horizontalAlignment: Text.AlignLeft
                    font.pointSize: 12
                    placeholderText: "User Name"

                }

                TextField{
                    id: userPassword
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: userName.bottom
                    anchors.topMargin: 20
                    height: parent.height/2
                    horizontalAlignment: Text.AlignLeft
                    font.pointSize: 12
                    echoMode: TextInput.Password
                    placeholderText: "Password"
                }
            }

            Button{
                id: buttonLogin
                anchors.left: parent.left
                anchors.leftMargin: Z50
                anchors.right: parent.right
                anchors.rightMargin: 75
                anchors.top: inputArea.bottom
                anchors.topMargin: 30
                height: 50
                text: "Ok"

                onClicked: {
                    AppModel.setUserName(userName.text)
                    AppModel.setPass(userPassword.text)
                    QmlHandler.qmlMessage("LOL")
                    QmlHandler.qmlSendEvent(ENUMS.LoginRequest)
                }
            }
        }
    }
}

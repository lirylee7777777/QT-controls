import QtQuick 2.9
import "./components" as Components

Rectangle {
    id: window
    anchors.fill: parent
    color: "#eee"

    Connections {
        target: Window
    }

    Rectangle {
        height: 34
        color: "#2a2a2a"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        Components.LLButton {
            width: 30
            image: "../../res/close.png"
            anchors.top: parent.top
            anchors.topMargin: 4
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 4
            anchors.right: parent.right
            anchors.rightMargin: 20
            onClicked: Window.close()
        }
    }
}

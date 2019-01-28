import QtQuick 2.12
import QtQuick.Window 2.12
import RootDelegate 1.0

import "qrc:/qml/qml/" as Custom

Rectangle {
    id: window
    anchors.fill: parent
    color: "#fff"

    Connections {
        target: rootDelegate
    }

    Custom.WindowHead {
        id: windowHead
        height: 44
        fontFamily: qsTr("Arial")
        fontSize: 18
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        onClose: {
            rootDelegate.close()
        }
    }

    Custom.WindowLeftList {
        id: windowLeftList
        x: 294
        y: 122
        width: 240
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: windowHead.bottom
        anchors.topMargin: 0
    }

    Rectangle {
        id: line
        width: 2
        color: "#ddd"
        anchors.left: windowLeftList.right
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: windowHead.bottom
        anchors.topMargin: 0
    }

    Custom.WindowTool {
        height: 40
        fontSize: 12
        anchors.left: line.right
        anchors.leftMargin: 30
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.top: windowHead.bottom
        anchors.topMargin: 20
    }

}































































/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:200;anchors_width:200;anchors_x:96;anchors_y:42}
D{i:2;anchors_height:44;anchors_width:640;anchors_x:24;anchors_y:108}
}
 ##^##*/

import QtQuick 2.0
import QtQuick.Layouts 1.3

import "qrc:/qml/qml/" as Custom

Item {
    id: windowTool

    property int fontSize: 26

    RowLayout {
        spacing: 20
        anchors.fill: parent

        Rectangle {

            Layout.preferredHeight: 0
            Layout.preferredWidth: 4
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#ddd"

            TextInput {
                id: textInput
                text: qsTr("请输入待检测的网址")
                font.pointSize: windowTool.fontSize
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 10
            }
        }

        Custom.Button {
            id: button1
            text: qsTr("开始")
            Layout.minimumWidth: 20
            Layout.maximumWidth: 100
            Layout.preferredHeight: 0
            Layout.preferredWidth: 0
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Custom.Button {
            id: button2
            text: qsTr("保存")
            Layout.minimumWidth: 20
            Layout.maximumWidth: 100
            Layout.preferredHeight: 0
            Layout.preferredWidth: 0
            Layout.rowSpan: 1
            Layout.columnSpan: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

    }
}


/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/

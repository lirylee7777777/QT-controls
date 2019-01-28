import QtQuick 2.0

Item {
    id: button

    property string text: ""
    property alias textColor: text.color
    property alias textSize: text.font.pointSize
    property string normalColor: "#f26b3a"
    property string hoverColor: "#e25b2a"
    property string pressColor: "#d24b1a"
    property int radius: 0
    signal click()

    Rectangle {
        id: rect
        anchors.fill: parent
        color: button.normalColor
        radius: button.radius

        Text {
            id: text
            anchors.centerIn: parent
            text: button.text
            font.pointSize: windowTool.fontSize
            color: "#fff"
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                rect.color = button.hoverColor
            }
            onExited: {
                rect.color = button.normalColor
            }
            onPressed: {
                rect.color = button.pressColor
            }
            onReleased: {
                if (mouseArea.contains(Qt.point(mouseX, mouseY))) {
                    rect.color = button.hoverColor
                    emit: button.click()
                }
            }
        }
    }
}

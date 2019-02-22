import QtQuick 2.0

Item {
    id: button

    property string color: "#2a2a2a"
    property string colorHover: "#5a5a5a"
    property string colorPress: "#5a5a5a"
    property string image: ""
    signal clicked()

    Rectangle {
        color: mouseArea.press ? button.colorPress : (mouseArea.enter ? button.colorHover : button.color)
        anchors.fill: parent

        Image {
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: button.image
        }

        MouseArea {
            id: mouseArea
            property bool enter: false
            property bool press: false
            hoverEnabled: true
            anchors.fill: parent
            onEntered: this.enter = true
            onExited: this.enter = false
            onPressed: this.press = true
            onReleased: this.press = false
            onClicked: {
                emit: button.clicked()
            }
        }
    }
}

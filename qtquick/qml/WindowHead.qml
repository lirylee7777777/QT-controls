import QtQuick 2.0

Rectangle {
    id: windowHead

    property alias fontFamily: element.font.family
    property alias fontSize: element.font.pixelSize
    property alias title: element.text
    signal close()

    height: 44
    color: "#2a2a2a"
    transformOrigin: Item.Center

    Text {
        id: element
        width: 252
        color: "#fff"
        text: qsTr("智能风险界面提示系统")
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        transformOrigin: Item.Center
        font.capitalization: Font.MixedCase
        font.family: "Arial"
        textFormat: Text.AutoText
        fontSizeMode: Text.Fit
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        lineHeight: 0.9
        elide: Text.ElideRight
        wrapMode: Text.WordWrap
        font.pixelSize: 14
    }

    Rectangle {
        id: rectangle1
        x: 468
        width: 24
        color: "#2a2a2a"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 20

        Image {
            id: image
            x: 0
            y: 0
            width: 34
            height: 30
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            fillMode: Image.PreserveAspectFit
            source: "qrc:/img/images/close.png"
        }

        MouseArea {
            id: mouseArea
            hoverEnabled: true
            anchors.fill: parent
            onClicked: {
                emit: windowHead.close()
            }
            onEntered: {
                rectangle1.color = "#5a5a5a"
            }
            onExited: {
                rectangle1.color = "#2a2a2a"
            }
        }

    }
}

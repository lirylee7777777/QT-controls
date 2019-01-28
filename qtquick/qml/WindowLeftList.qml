import QtQuick 2.0

ListView {

    id: windowLeftList
    property int itemHeight: 60
    flickableDirection: Flickable.AutoFlickDirection

    model: ListModel {
        id: fruitModel

        ListElement {
            source: "https://www.iconfont.cn/search/index?q=%E4%B8%89%E8%A7%92"
        }
        ListElement {
            source: "https://blog.csdn.net/qingyulove/article/details/79026951"
        }
        ListElement {
            source: "http://www.runoob.com/manual/lua53doc/manual.html"
        }
        ListElement {
            source: "https://github.com/cloudwu/skynet/wiki"
        }
        ListElement {
            source: "http://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/headers/"
        }
        ListElement {
            source: "http://doc.wzl.com/docs/php/php-1apdpvmqhjj2d"
        }
        ListElement {
            source: "https://www.nodebeginner.org/index-zh-cn.html#hello-world"
        }
    }

    delegate: Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        height: windowLeftList.itemHeight
        color: "#ffffff"

        Image {
            id: imageSan
            height: 8
            width: 8
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10
            fillMode: Image.PreserveAspectFit
            source: "qrc:/img/images/san.png"
        }

        Image {
            id: imageFile
            height: 24
            width: 24
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: imageSan.right
            anchors.leftMargin: 10
            fillMode: Image.PreserveAspectFit
            source: "qrc:/img/images/file.png"
        }

        Text {
            id: name
            text: source
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: imageFile.right
            anchors.leftMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
            wrapMode: Text.WordWrap
        }

        Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.bottom: parent.bottom
            height: 1
            color: "#dddddd"
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/

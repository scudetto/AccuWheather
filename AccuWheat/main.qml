import QtQuick 2.7
import QtQuick.Window 2.2

//import Valid 1.0

Window {
    //id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    ValidateScreenUI{
        id: valid
        anchors.centerIn: parent.center
    }

    /*MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }*/
}

import QtQuick 2.1
import QtQuick.Window 2.2

//import Valid 1.0

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    /*ValidateScreenUI{
        id: valid
        anchors.centerIn: parent.center
    }*/

    Loader{
        id: loader
        source: "ValidateScreenUI.qml"
        property bool valid: item !== null
    }

    Connections{
        ignoreUnknownSignals: true
        target: loader.valid ? loader.item : null
        onValidLocation: loader.source = "WheatherViewUI.qml"
    }

}

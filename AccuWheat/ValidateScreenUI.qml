import QtQuick 2.0
import Valid 1.0

ValidScreen{
    Item{
        id: validMain
        width: 300
        height: 50
        visible: true

        Rectangle{
            anchors.fill: parent
            border.width: 2

            TextInput{
                id: textInput
                y: 10
                x: 10
                color: "black"
                text: "Please provide appKey"
            }
        }

        Rectangle{
            id: setButton
            anchors.top: parent.bottom
            x: 130
            width: 90
            height: 30
            color: "lightblue"

            Text{
                id: textButton
                anchors.centerIn: parent
                text: "Set"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                  setKeyId(textInput.text);
                  validMain.state = "Validating"
                }
            }
        }

        states:[
            State{
                name: "Validating"
                PropertyChanges {
                    target: textButton
                    text: "Validating"
                }
            },
            State{
                 name: "ValidateOK"
                 when: (isValid != false)
                 PropertyChanges{
                    target: validMain
                    visible: false
                 }
           }

        ]
    }
}

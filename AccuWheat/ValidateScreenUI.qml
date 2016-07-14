import QtQuick 2.0
import Valid 1.0

ValidScreen{

    Item{

        id: validMain
        width: 300
        height: 50
        visible: true
        opacity: 100


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
                  //setKeyId(textInput.text);
                  setKeyId("qEqpAfbLGktQDq4tqXH8q2P0lZN6bnbo");//temp solution
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

                PropertyChanges{
                   target: textInput
                   text: "Validating..."
                }
            },
            State{
                 name: "ValidateOK"
                 when: (isValid == 1)
                 PropertyChanges{
                    target: validMain
                    visible: false
                 }

                 PropertyChanges{
                    target: textInput
                    text: "Validatio with appKey OK"
                 }
           },

           State{
                 name: "ValidateFailed"
                 when: (isValid == 0)
                 PropertyChanges{
                    target: textInput
                    text: "ValidationFailed, please provide proper appKey"
                 }
           }

        ]
    }
}

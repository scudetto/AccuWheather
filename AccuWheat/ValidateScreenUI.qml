import QtQuick 2.0
import Valid 1.0

ValidScreen{

    Item{

        id: validMain
        width: 300
        height: 50
        visible: true
        opacity: 100
        state: "Begin"

        Rectangle{
            id: textRect
            anchors.fill: parent
            border.width: 2

            TextInput{
                id: textInput
                y: 10
                x: 10
                color: "black"
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
                    switch(validMain.state)
                    {
                        case "ValidateAppKeyOK":
                            setLocation(textInput.text);
                            break;
                        case "ValidateAppKeyFailed":
                            setKeyId("qEqpAfbLGktQDq4tqXH8q2P0lZN6bnbo");
                            break;
                        case "Begin":
                            setKeyId("qEqpAfbLGktQDq4tqXH8q2P0lZN6bnbo");
                            break;
                    }
                }
            }
        }

        states:[

            State{
                  name: "Begin"
                  PropertyChanges{
                     target: textInput
                     text: "Please provide proper appKey"
                  }
            },
           State{
                 name: "ValidateAppKeyFailed"
                 when: (isValid == 0 && requestType == 0)
                 PropertyChanges{
                    target: textInput
                    text: "ValidationFailed, please provide proper appKey"
                 }
           },
            State{
                name: "ValidateLocationFailed"
                when: (isValid == 0 && requestType == 1)
                PropertyChanges{
                   target: textInput
                   text: "ValidationFailed, please provide proper location"
                }
            },

            State{
                  when: (isValid == 1 && requestType == 0)
                  name: "ValidateAppKeyOK"
                  PropertyChanges{
                     target: textInput
                     text: "Please provide proper location"
                  }
            }

        ]
    }
}

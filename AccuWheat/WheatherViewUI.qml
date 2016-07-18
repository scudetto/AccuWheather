import QtQuick 2.0

import Valid 1.0

WheatherView{
    Item {


        Rectangle{
            width: 100
            height: 100
            color: "red"

            Text{
                anchors.fill: parent
                text: "some"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: printText()
            }

        }

    }
}

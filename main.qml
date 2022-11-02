import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15


Window {
    width: 400
    height: 400
    visible: true
    title: qsTr("QtCalculator")

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        TextField {
            text: Calculator.outputBuffer
            Layout.fillWidth: true
            font.pixelSize: 30
            horizontalAlignment: TextInput.AlignRight

            background: Rectangle {
                color: "lightgrey"
                radius: 5
            }

            readOnly: true
        }

        GridLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            columns: 4

            Repeater {
                model: ["C", "←", ".", "/", "7", "8", "9", "*", "4", "5", "6", "+", "1", "2", "3", "-", "(", "0", ")", "=", "↑", "↓"]

                Button {
                    implicitHeight: 50
                    implicitWidth: 100
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    contentItem: Text {
                        text: modelData
                        font.pixelSize: 25
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    onClicked: Calculator.process(modelData)
                }
            }
        }
    }
}

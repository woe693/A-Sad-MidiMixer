import QtQuick
import QtQuick.Controls as Controls
import QtQuick.Layouts


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("A Sad MidiMixer")

    Text {
        text: "test"
    }

    RowLayout{
        spacing: 16
        Rectangle{
            width:200
        }
        Repeater {
            model: 8   // number of sliders

            Rectangle{

                width: 100
                height: 600

                RowLayout{
                    ColumnLayout{
                        width:50
                        height:50
                        spacing: 50
                        Rectangle{
                            color:0
                            Controls.Button{
                                text: "S"
                            }
                        }
                        Rectangle{
                            color:0
                            Controls.Button{
                                text: "M"
                            }
                        }
                        Rectangle{
                            color:0
                            Controls.Button{
                                text: "R"
                            }
                        }

                    }

                    Controls.Slider {
                        orientation: Qt.Vertical
                        from: 0
                        to: 1
                        Layout.preferredHeight: 220
                    }
                }
            }
        }

        Rectangle{
            width:200
        }
    }
}



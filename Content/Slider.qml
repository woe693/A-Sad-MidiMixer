import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Slider {
    id: numberPad

    RowLayout{
        spacing:1
        Rectangle{
            height:52
            color:"grey"
        }
        Rectangle{
            height:208
            color:"white"
        }
    }
}

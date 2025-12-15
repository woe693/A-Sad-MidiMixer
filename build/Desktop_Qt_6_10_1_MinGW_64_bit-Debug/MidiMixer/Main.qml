import QtQuick
import QtQuick.Controls as Controls
import QtQuick.Layouts

import "Mixers/NanoKontrol2"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("A Sad MidiMixer")
    color:"#4C3B4D"

    NanoKontrol2{

    }
}



import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle{
    color:"transparent"
    RowLayout{
        spacing:100


        ColumnLayout{
            spacing:100
            Rectangle{
                width:1000
                height:260
                color:"black"
                ColumnLayout{
                    spacing:1
                    Rectangle{
                        width:333
                    }
                    Rectangle{
                        width:666
                        height:260
                        RowLayout{
                            Repeater{
                                model:8
                                VolumeFader{

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


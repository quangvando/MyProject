import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls 2.12

import MyPoligon 1.0
import MyLine 1.0
import MyPath 1.0
//import DataForCalculate 1.0

Window {
    id: appWindow
    width: 640
    height: 690
    visible: true
    title: qsTr("")
    color: "white"

    Repeater {
        id:r1
        anchors.fill: parent
        model: myPointDataModel1
        delegate: Rectangle{
            x: xn
            y: yn
            width: 2
            height: 2
            color: "blue"
        }
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            myBaseDataModel1.getPoint(mouseX, mouseY)
            myBaseDataModel2.getPoint(mouseX, mouseY)
            myPointDataModel1.addItem(mouseX, mouseY)
            mydataForCalculate.getPoint(mouseX, mouseY)
            //mydataForCalculate.checkInOrOut()
        }
    }

    Repeater {
        id:r2
        anchors.fill: parent
        model: myBaseDataModel1
        delegate: MyPoligon{
            poli: pointList
            anchors.fill: parent
            color: "blue"
        }
    }
    Button {
        width: 100
        height: 30
        text: "GetPoligon"
        onClicked: {
            //myBaseDataModel2.addItem()
            myBaseDataModel1.addItem()
            mydataForCalculate.getPoints()
        }
    }
    Button {
        y: 40
        width: 100
        height: 30
        text: "Get all"
        onClicked: {
            mydataForCalculate.getPointOder();
            //mydataForCalculate.getCases();
            //mydataForCalculate.checkFist()
        }
    }
    Button {
        y: 80
        width: 100
        height: 30
        text: "Get the end"
        onClicked: {
            //mydataForCalculate.getPointOder();
            //mydataForCalculate.getCases();
            mydataForCalculate.checkFist()
        }
    }
    Repeater {
        id:r3
        anchors.fill: parent
        model: myBaseDataModel2
        delegate: MyLine{
            line: pointList
            anchors.fill: parent
            color: "yellow"
        }
    }
//    Repeater {
//        id:r4
//        anchors.fill: parent
//        model: myBaseDataModel2
//        delegate: MyPath{
//            path: pointList
//            anchors.fill: parent
//            color: "blue"
//        }
//    }
}


QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ClassDraw/drawLine.cpp \
        ClassDraw/drawMyPath.cpp \
        ClassDraw/drawPoligon.cpp \
        Controller/controller.cpp \
        DataModel/dataBase.cpp \
        DataModel/dataForCalculate.cpp \
        DataModel/myBaseDataModel.cpp \
        DataModel/myPointDataModel.cpp \
        main.cpp \  

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ClassDraw/drawLine.h \
    ClassDraw/drawMyPath.h \
    ClassDraw/drawPoligon.h \
    Controller/controller.h \
    DataModel/dataBase.h \
    DataModel/dataForCalculate.h \
    DataModel/myBaseDataModel.h \
    DataModel/myPointDataModel.h

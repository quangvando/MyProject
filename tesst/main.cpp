#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "./DataModel/myPointDataModel.h"
#include "./ClassDraw/drawLine.h"
#include "./DataModel/myBaseDataModel.h"
#include "./ClassDraw/drawPoligon.h"
#include "./ClassDraw/drawMyPath.h"
#include "./DataModel/dataForCalculate.h"
//#include "./DataModel/checkinter.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    myBaseDataModel myBaseDataModel1;
    engine.rootContext()->setContextProperty("myBaseDataModel1", &myBaseDataModel1);
    myBaseDataModel myBaseDataModel2;
    engine.rootContext()->setContextProperty("myBaseDataModel2", &myBaseDataModel2);
    myPointDataModel myPointDataModel1;
    engine.rootContext()->setContextProperty("myPointDataModel1", &myPointDataModel1);
    dataForCalculate mydataForCalculate;
    engine.rootContext()->setContextProperty("mydataForCalculate", &mydataForCalculate);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    //qmlRegisterType<myPointDataModel>("MyPointDataModel", 1, 0, "MyPointDataModel");
    //qmlRegisterType<dataForCalculate>("DataForCalculate", 1, 0, "DataForCalculate");
    qmlRegisterType<drawMyPath>("MyPath", 1, 0, "MyPath");
    qmlRegisterType<drawPoligon>("MyPoligon", 1, 0, "MyPoligon");
    qmlRegisterType<drawLine>("MyLine", 1, 0, "MyLine");

    engine.load(url);

    return app.exec();
}

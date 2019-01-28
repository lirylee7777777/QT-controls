#include <QQuickView>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "rootview.h"
#include "rootdelegate.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    RootView root;

    qmlRegisterType<RootDelegate>("RootDelegate", 1, 0, "RootDelegate");
    RootDelegate delegate;
    root.rootContext()->setContextProperty("rootDelegate", &delegate);

    root.setResizeMode(QQuickView::SizeRootObjectToView);
    root.setSource(QUrl(QStringLiteral("qrc:/qml/qml/main.qml")));
    root.show();

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/qml/qml/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    return app.exec();
}

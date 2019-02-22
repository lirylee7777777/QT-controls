#include <QGuiApplication>
#include "src/window.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    LL::Window window;
    window.setResizeMode(QQuickView::SizeRootObjectToView);
    window.setSource(QUrl::fromLocalFile("D:/Code/test_app/qt_controls/qml/LLWindow.qml"));
    window.show();

    return app.exec();
}

#include "rootdelegate.h"

#include "rootview.h"

RootDelegate::RootDelegate(QObject *parent) : QObject(parent)
{

}

void RootDelegate::close() {
    auto *instance = RootView::getInstance();
    if (instance) {
        instance->close();
    }
}

#include "rootview.h"

#include <QMouseEvent>
#if _MSC_VER
#include <windows.h>
#include <windowsx.h>
#endif

RootView* RootView::instance = nullptr;

RootView::RootView() :
    QQuickView(),
    mCanMove(true),
    mCanZoom(true),
    mMoveing(false)
{
    headerHeight = 44;
    this->instance = this;
    setFlag(Qt::FramelessWindowHint);
    setMinimumSize(QSize(800, 480));
}

void RootView::setMove(bool move)
{
    mCanMove = move;
}

void RootView::setZoom(bool zoom)
{
    mCanZoom = zoom;
}

void RootView::mousePressEvent(QMouseEvent *event)
{
    QQuickView::mousePressEvent(event);
    if (mCanMove) {
        QPoint p = mapFromGlobal(event->globalPos());
        QRect rect = QRect(0, 0, width(), headerHeight);
        if (rect.contains(p)) {
            mMoveing = true;
            mMovePosition = event->globalPos() - position();
        }
    }
}

void RootView::mouseMoveEvent(QMouseEvent *event)
{
    QQuickView::mouseMoveEvent(event);
    if (mCanMove) {
        if (mMoveing &&
            (event->buttons() == Qt::LeftButton) &&
            (event->globalPos() - mMovePosition).manhattanLength() > 10) {
            setPosition(event->globalPos() - mMovePosition);
            mMovePosition = event->globalPos() - position();
        }
    }
}

void RootView::mouseReleaseEvent(QMouseEvent *event)
{
    QQuickView::mouseReleaseEvent(event);
    mCanMove && (mMoveing = false);
}

void RootView::mouseDoubleClickEvent (QMouseEvent *event)
{
    QQuickView::mouseDoubleClickEvent(event);
    if (mCanMove) {
        QPoint p = mapFromGlobal(event->globalPos());
        QRect rect = QRect(0, 0, width(), this->headerHeight);
        if (rect.contains(p)) {
            (windowState() == Qt::WindowMaximized || windowState() == Qt::WindowFullScreen) ? showNormal() : showMaximized();
        }
    }
}

bool RootView::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
#if _MSC_VER
    if (mCanZoom) {
        MSG *msg = static_cast<MSG*>(message);
        switch (msg->message) {
            case WM_NCHITTEST:
                if (windowState() == Qt::WindowMaximized || windowState() == Qt::WindowFullScreen) {
                    return false;
                }
                int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
                int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
                if(xPos > 0 && xPos <= 5 && yPos > 0 && yPos <= 5) {
                    *result = HTTOPLEFT;
                    return true;
                }
                if(xPos > (this->width() - 5) && xPos <= this->width() && yPos > 0 && yPos <= 5) {
                    *result = HTTOPRIGHT;
                    return true;
                }
                if(xPos > 0 && xPos <= 5 && yPos > (this->height() - 5) && yPos <= this->height()) {
                    *result = HTBOTTOMLEFT;
                    return true;
                }
                if(xPos > (this->width() - 5) && xPos <= this->width() && yPos > (this->height() - 5) && yPos <= this->height()) {
                    *result = HTBOTTOMRIGHT;
                    return true;
                }
                if(xPos > 0 && xPos <= 5) {
                    *result = HTLEFT;
                    return true;
                }
                if(xPos > (this->width() - 5) && xPos <= this->width()) {
                    *result = HTRIGHT;
                    return true;
                }
                if(yPos > 0 && yPos <= 5) {
                    *result = HTTOP;
                    return true;
                }
                if(yPos > (this->height() - 5) && yPos <= this->height()) {
                    *result = HTBOTTOM;
                    return true;
                }
                return QQuickView::nativeEvent(eventType, message, result);
        }
    }
#endif
    return QQuickView::nativeEvent(eventType, message, result);
}

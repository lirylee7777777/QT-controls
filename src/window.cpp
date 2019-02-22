#include "window.h"

#include <QMouseEvent>
#include <QQmlContext>
#if _MSC_VER
#include <Windows.h>
#include <windowsx.h>
#endif

using namespace LL;

Window::Window() :
    QQuickView(),
    m_canMove(true),
    m_canZoom(true),
    m_moveing(false),
    m_headerHeight(34),
    m_movePosition(0, 0),
    p_delegate(new WindowDelegate(this))
{
    setFlag(Qt::FramelessWindowHint);
    setWidth(640);
    setHeight(480);
    rootContext()->setContextProperty("Window", p_delegate);
}

Window::~Window()
{
    delete p_delegate;
}

void Window::mousePressEvent(QMouseEvent *event)
{
    QQuickView::mousePressEvent(event);
    if (m_canMove) {
        QPoint p = mapFromGlobal(event->globalPos());
        QRect rect = QRect(0, 0, width(), m_headerHeight);
        if (rect.contains(p)) {
            m_moveing = true;
            m_movePosition = event->globalPos() - position();
        }
    }
}

void Window::mouseMoveEvent(QMouseEvent *event)
{
    QQuickView::mouseMoveEvent(event);
    if (m_canMove &&
          m_moveing &&
          (event->buttons() == Qt::LeftButton) &&
          (event->globalPos() - m_movePosition).manhattanLength() > 10) {
        setPosition(event->globalPos() - m_movePosition);
        m_movePosition = event->globalPos() - position();
    }
}

void Window::mouseReleaseEvent(QMouseEvent *event)
{
    QQuickView::mouseReleaseEvent(event);
    m_canMove && (m_moveing = false);
}

void Window::mouseDoubleClickEvent(QMouseEvent *event)
{
    QQuickView::mouseDoubleClickEvent(event);
    if (m_canMove) {
        QPoint p = mapFromGlobal(event->globalPos());
        QRect rect = QRect(0, 0, width(), this->m_headerHeight);
        if (rect.contains(p)) {
            windowState() == Qt::WindowMaximized ? showNormal() : showMaximized();
        }
    }
}

bool Window::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
#if _MSC_VER
    if (m_canZoom) {
        MSG *msg = static_cast<MSG*>(message);
        if (msg->message == WM_NCHITTEST) {
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
        }
    }
#endif
    return QQuickView::nativeEvent(eventType, message, result);
}

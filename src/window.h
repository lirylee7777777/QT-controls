#ifndef WINDOW_H
#define WINDOW_H

#include <QQuickView>

namespace LL {

class Window;
class WindowDelegate;

class Window : public QQuickView
{
    Q_OBJECT
    friend class WindowDelegate;
public:
    Window();
    ~Window();

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickEvent (QMouseEvent*);
    bool nativeEvent(const QByteArray&, void*, long*);

private:
    bool m_canMove;
    bool m_canZoom;
    bool m_moveing;
    int m_headerHeight;
    QPoint m_movePosition;
    WindowDelegate* p_delegate;
};

class WindowDelegate : public QObject
{
    Q_OBJECT
public:
    WindowDelegate(Window* window) : QObject(nullptr), p_window(window) {}

    Q_INVOKABLE void close();
    Q_INVOKABLE void setMove(bool);
    Q_INVOKABLE void setZoom(bool);
    Q_INVOKABLE void setHeader(int);

private:
    Window* p_window;
};

inline void WindowDelegate::close() { p_window->close(); }

inline void WindowDelegate::setMove(bool move) { p_window->m_canMove = move; }

inline void WindowDelegate::setZoom(bool zoom) { p_window->m_canZoom = zoom; }

inline void WindowDelegate::setHeader(int height) { p_window->m_headerHeight = height; }

}

#endif // WINDOW_H

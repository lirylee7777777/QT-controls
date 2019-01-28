#ifndef ROOTVIEW_H
#define ROOTVIEW_H

#include <QObject>
#include <QQuickView>

class RootView : public QQuickView
{
    Q_OBJECT
public:
    explicit RootView();

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickEvent (QMouseEvent*);
    bool nativeEvent(const QByteArray&, void*, long*);

    static RootView* getInstance();

signals:

public slots:

private:
    void setMove(bool);
    void setZoom(bool);

    int headerHeight;
    bool mCanMove;
    bool mCanZoom;
    bool mMoveing;
    QPoint mMovePosition;

    static RootView* instance;
};

inline RootView* RootView::getInstance() {
    return instance;
}

#endif // ROOTVIEW_H

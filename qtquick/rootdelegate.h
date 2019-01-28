#ifndef ROOTDELEGATE_H
#define ROOTDELEGATE_H

#include <QObject>

class RootDelegate : public QObject
{
    Q_OBJECT
public:
    explicit RootDelegate(QObject *parent = nullptr);

signals:

public slots:

    void close();
};

#endif // ROOTDELEGATE_H

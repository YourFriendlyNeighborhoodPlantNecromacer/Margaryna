#ifndef BUCKETTOOL_H
#define BUCKETTOOL_H

#include "../Tool.h"
#include <QImage>
#include <QColor>


class BucketTool : public Tool{
public:
    QImage *selectedLayer;
    QImage *pendingLayer;
    QColor color;
    int tolerance;
    bool isGlobal;
    bool active = false;

    BucketTool(QImage* img, QImage* pendingLayer, QColor selected_color = QColor(0, 0, 0), bool isGlobal = false, int colorOffsetTolerance=0);

    void press(int x, int y, bool alternative) override;
    void move(int x, int y, bool alternative) override;
    void release(int x, int y, bool alternative) override;
    void cancel() override;
};
#endif // BUCKETTOOL_H

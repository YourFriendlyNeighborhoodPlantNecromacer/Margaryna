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

    BucketTool(QImage* img, QImage* pendingLayer, QColor selected_color = QColor(0, 0, 0), int colorOffsetTolerance=0, bool global=false);

    void press(int x, int y) override;
    void move(int x, int y) override;
    void release(int x, int y) override;
    void cancel() override;
};
#endif // BUCKETTOOL_H

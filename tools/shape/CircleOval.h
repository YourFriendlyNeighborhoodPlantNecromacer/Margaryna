#ifndef CIRCLEOVAL_H
#define CIRCLEOVAL_H
#include "tools/Tool.h"
#include <QImage>
#include <QColor>

class CircleOval : public Tool{
public:
    QImage* selectedLayer;
    QImage* pendingLayer;
    QImage* toolPreviewLayer;
    QColor color;
    bool active = false;
    int lineRadius;
    int startingX;
    int startingY;
    int endingX;
    int endingY;

    CircleOval(QImage* img, QImage* pendingLayer, QImage* previewLayer, QColor selected_color = QColor(0, 0, 0), int lineWidthRadius = 3);

    void press(int x, int y) override;
    void move(int x, int y) override;
    void release(int x, int y) override;
    void cancel() override;
};

#endif // CIRCLEOVAL_H

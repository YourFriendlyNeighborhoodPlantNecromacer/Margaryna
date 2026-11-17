#ifndef CIRCLEOVALTOOL_H
#define CIRCLEOVALTOOL_H
#include "tools/Tool.h"
#include <QImage>
#include <QColor>

class CircleOvalTool : public Tool{
public:
    QImage* selectedLayer;
    QImage* pendingLayer;
    QImage* toolPreviewLayer;
    QColor primaryColor;
    QColor secondaryColor;
    bool active = false;
    int lineRadius;
    int cricleRadius;
    int startingX;
    int startingY;
    int endingX;
    int endingY;

    CircleOvalTool(QImage* img, QImage* pendingLayer, QImage* previewLayer, QColor primaryColor, QColor secondaryColor, int lineWidthRadius = 3);

    void press(int x, int y, bool alternative) override;
    void move(int x, int y, bool alternative) override;
    void release(int x, int y, bool alternative) override;
    void cancel() override;
};

#endif // CIRCLEOVALTOOL_H

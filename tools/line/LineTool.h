#ifndef LINETOOL_H
#define LINETOOL_H

#include "tools/Tool.h"
#include <QImage>

class LineTool : public Tool{
public:
    QImage* selectedLayer;
    QImage* pendingLayer;
    QImage* toolPreviewLayer;
    QColor color;
    bool active = false;
    int radius;
    int startingX;
    int startingY;
    int endingX;
    int endingY;

    LineTool(QImage* img, QImage* pendingLayer, QImage* previewLayer, QColor selected_color = QColor(0, 0, 0), int lineWidthRadius = 3);

    void press(int x, int y) override;
    void move(int x, int y) override;
    void release(int x, int y) override;
    void cancel() override;
};
#endif // LINETOOL_H

#ifndef PENTOOL_H
#define PENTOOL_H

#include <QImage>
#include <cstdlib>
#include "tools/Tool.h"
//#include <iostream>

class PenTool : public Tool{
public:
    QImage* selectedLayer;
    QImage* pendingLayer;
    QColor color;
    int radius;
    bool active = false;
    int lastX;
    int lastY;

    PenTool(QImage* img, QImage* pendingLayer, int penRadius = 3, QColor selected_color = QColor(0,0,0,255));

    void press(int x, int y) override;
    void move(int x, int y) override;
    void release(int x, int y) override;
    void cancel() override;
};


#endif // PENTOOL_H

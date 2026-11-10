#ifndef PENTOOL_H
#define PENTOOL_H

#include <QImage>
#include <cstdlib>
#include "tools/Tool.h"
//#include "tools/ToolFunctions.h"
//#include <iostream>

class PenTool : public Tool{
public:
    QImage *selectedLayer;
    QImage *pendingLayer;
    QColor color;
    int radius;
    bool active = false;
    int lastX;
    int lastY;

    PenTool(QImage* img, QImage* pendingLayer, int penRadius = 3, QColor selected_color = QColor(0,0,0));

    void press(int x, int y);
    void move(int x, int y);
    void release(int x, int y);
    void cancel();

    void putPixel(int x, int y);
    void strokeTo(int x1, int y1);
};


#endif // PENTOOL_H

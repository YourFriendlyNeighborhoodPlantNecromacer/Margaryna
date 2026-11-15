#include <QImage>
#include <QColor>
#include "PenTool.h"
#include "../ToolFunctions.h"
//#include <iostream>

PenTool::PenTool(QImage* img, QImage* pendingLayer, int penRadius, QColor selected_color) : selectedLayer(img), pendingLayer(pendingLayer), color(selected_color), radius(penRadius) {
    active = false;
}

void PenTool::press(int x, int y){
    active = true;
    lastX = x;
    lastY = y;
    safeStamp(pendingLayer, color, radius, x, y);
}

void PenTool::move(int x, int y){
    if (!active) return;
    safeDrawLineBetween(pendingLayer, color, radius, x, y, lastX, lastY);
    lastX = x;
    lastY = y;
}

void PenTool::release(int x, int y){
    safeDrawLineBetween(pendingLayer, color, radius, x, y, lastX, lastY);
    applyLayer(selectedLayer, pendingLayer);
    pendingLayer->fill(Qt::transparent);
    active = false;
}

void PenTool::cancel(){
    pendingLayer->fill(Qt::transparent);
    active = false;
}

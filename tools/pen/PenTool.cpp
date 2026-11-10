#include <QImage>
#include <QColor>
#include "PenTool.h"
#include "../ToolFunctions.h"
#include <iostream>

PenTool::PenTool(QImage* img, int penRadius, QColor selected_color) : selectedLayer(img), color(selected_color), radius(penRadius) {
    active = false;
}

void PenTool::press(int x, int y){
    active = true;
    lastX = x;
    lastY = y;
    safeStamp(selectedLayer, color, radius, x, y);
}

void PenTool::move(int x, int y){
    if (!active) return;
    safeDrawLineBetween(selectedLayer, color, radius, x, y, lastX, lastY);
    lastX = x;
    lastY = y;
}

void PenTool::release(int x, int y){
    safeDrawLineBetween(selectedLayer, color, radius, x, y, lastX, lastY);
    active = false;
}

void PenTool::cancel(){
    active = false;
}

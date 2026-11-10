#include "LineTool.h"
#include "tools/ToolFunctions.h"
#include <QImage>
#include <iostream>

LineTool::LineTool(QImage* img, QImage* pendingLayer, QImage* previewLayer, QColor selected_color, int lineWidthRadius) : selectedLayer(img), pendingLayer(pendingLayer), toolPreviewLayer(previewLayer), color(selected_color), radius(lineWidthRadius) {
}

void LineTool::press(int x, int y){
    active = true;
    startingX = x;
    endingX = x;
    startingY = y;
    endingY = y;
    toolPreviewLayer->fill(Qt::transparent);
    safeDrawLineBetween(toolPreviewLayer, color, radius, startingX, startingY, endingX, endingY);
}

void LineTool::move(int x, int y){
    if (!active) return;
    endingX = x;
    endingY = y;
    toolPreviewLayer->fill(Qt::transparent);
    safeDrawLineBetween(toolPreviewLayer, color, radius, startingX, startingY, endingX, endingY);
}

void LineTool::release(int x, int y){
    active = false;
    endingX = x;
    endingY = y;
    toolPreviewLayer->fill(Qt::transparent);
    safeDrawLineBetween(pendingLayer, color, radius, startingX, startingY, endingX, endingY);
    applyLayer(selectedLayer, pendingLayer);
    pendingLayer->fill(Qt::transparent);
}

void LineTool::cancel(){
    active = false;
}

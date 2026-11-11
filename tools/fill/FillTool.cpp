#include "FillTool.h"
#include "../ToolFunctions.h"
//#include <iostream>

FillTool::FillTool(QImage* img, QImage* pendingLayer, QColor selected_color, int colorOffsetTolerance, bool global) : selectedLayer(img), pendingLayer(pendingLayer), color(selected_color), tolerance(colorOffsetTolerance), isGlobal(global){}

void FillTool::press(int x, int y){
    if(!isInBounds(selectedLayer, x, y))return;
    if(isGlobal)globalFloodFill(selectedLayer, pendingLayer, color, x, y);
    else        floodFill(selectedLayer, pendingLayer, color, x, y);
    applyLayer(selectedLayer, pendingLayer);
    pendingLayer->fill(Qt::transparent);
}

void FillTool::move(int x, int y){}

void FillTool::release(int x, int y){}

void FillTool::cancel(){}

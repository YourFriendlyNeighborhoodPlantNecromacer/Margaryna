#include "BucketTool.h"
#include "../ToolFunctions.h"
//#include <iostream>

BucketTool::BucketTool(QImage* img, QImage* pendingLayer, QColor selected_color, int colorOffsetTolerance, bool global) : selectedLayer(img), pendingLayer(pendingLayer), color(selected_color), tolerance(colorOffsetTolerance), isGlobal(global){}

void BucketTool::press(int x, int y){
    if(!isInBounds(selectedLayer, x, y))return;
    if(color.alpha()==0)return;
    if(isGlobal)globalFloodFill(selectedLayer, pendingLayer, color, x, y);
    else        floodFill(selectedLayer, pendingLayer, color, x, y);
    applyLayer(selectedLayer, pendingLayer);
    pendingLayer->fill(Qt::transparent);
}

void BucketTool::move(int x, int y){}

void BucketTool::release(int x, int y){}

void BucketTool::cancel(){}

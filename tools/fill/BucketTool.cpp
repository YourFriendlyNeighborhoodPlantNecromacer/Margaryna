#include "BucketTool.h"
#include "../ToolFunctions.h"
#include <iostream>

BucketTool::BucketTool(QImage* img, QImage* pendingLayer, QColor selected_color, bool isGlobal, int colorOffsetTolerance) : selectedLayer(img), pendingLayer(pendingLayer), isGlobal(isGlobal), color(selected_color), tolerance(colorOffsetTolerance){}

void BucketTool::press(int x, int y, bool alternative){
    if(!isInBounds(selectedLayer, x, y))return;
    if(color.alpha()==0)return;
    if(isGlobal)globalFloodFill(selectedLayer, pendingLayer, color, x, y);
    else{
        std::cout << "local" << std::endl;
        floodFill(selectedLayer, pendingLayer, color, x, y);
    }applyLayer(selectedLayer, pendingLayer);
    pendingLayer->fill(Qt::transparent);
}

void BucketTool::move(int x, int y, bool alternative){}

void BucketTool::release(int x, int y, bool alternative){}

void BucketTool::cancel(){}

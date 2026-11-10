#include "FillTool.h"
#include "../ToolFunctions.h"

FillTool::FillTool(QImage* img, QColor selected_color, int colorOffsetTolerance, bool global) : selectedLayer(img), color(selected_color), tolerance(colorOffsetTolerance), isGlobal(global){}

void FillTool::press(int x, int y){
    if(!isInBounds(selectedLayer, x, y))return;
    if(isGlobal)globalFloodFill(selectedLayer, color, x, y);
    else        floodFill(selectedLayer, color, x, y);
}

void FillTool::move(int x, int y){}
void FillTool::release(int x, int y){}
void FillTool::cancel(){}

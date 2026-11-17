#include "CircleOvalTool.h"
#include "tools/ToolFunctions.h"
#include <iostream>

CircleOvalTool::CircleOvalTool(QImage* img, QImage* pendingLayer, QImage* previewLayer, QColor primaryColor, QColor secondaryColor, int lineThickness) :
    selectedLayer(img), pendingLayer(pendingLayer), toolPreviewLayer(previewLayer), primaryColor(primaryColor), secondaryColor(secondaryColor), lineThickness(lineThickness){
    active = false;
    startingX=0;
    startingY=0;
    endingX=0;
    endingY=0;
}

void CircleOvalTool::press(int x, int y, bool alternative){
    startingX=x;
    startingY=y;
    endingX=x;
    endingY=y;
    toolPreviewLayer->fill(Qt::transparent);
    drawCircle(toolPreviewLayer, primaryColor, startingX, startingY, getDistance(startingX, startingY, endingX, endingY), lineThickness);
    std::cout << "pressed" << std::endl;
}

void CircleOvalTool::move(int x, int y, bool alternative){
    endingX=x;
    endingY=y;
    toolPreviewLayer->fill(Qt::transparent);
    if(alternative)std::cout << "Drawing Elipse" << std::endl;
    else {
        std::cout << "Drawing circle" << std::endl;
        drawCircle(toolPreviewLayer, primaryColor, startingX, startingY, getDistance(startingX, startingY, endingX, endingY), lineThickness);
    }
}

void CircleOvalTool::release(int x, int y, bool alternative){
    endingX=x;
    endingY=y;
    toolPreviewLayer->fill(Qt::transparent);
    drawCircle(pendingLayer, primaryColor, startingX, startingY, getDistance(startingX, startingY, endingX, endingY), lineThickness);
    floodFill(pendingLayer, pendingLayer, secondaryColor, startingX, startingY);
    applyLayer(selectedLayer, pendingLayer);
    pendingLayer->fill(Qt::transparent);
}

void CircleOvalTool::cancel(){
    std::cout << "SHAKIRA" << std::endl;
}

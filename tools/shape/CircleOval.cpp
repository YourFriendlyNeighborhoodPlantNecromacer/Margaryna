#include "CircleOval.h"

CircleOval::CircleOval(QImage* img, QImage* pendingLayer, QImage* previewLayer, QColor selected_color, int lineWidthRadius) :
    selectedLayer(img), pendingLayer(pendingLayer), toolPreviewLayer(previewLayer), color(selected_color), lineRadius(lineWidthRadius){
    active = false;
    startingX=0;
    startingY=0;
    endingX=0;
    endingY=0;
}

void CircleOval::press(int x, int y){
    startingX=x;
    startingY=y;
    endingX=x;
    endingY=y;
}

void CircleOval::move(int x, int y){
    endingX=x;
    endingY=y;
}

void CircleOval::release(int x, int y){
    endingX=x;
    endingY=y;
}

void CircleOval::cancel(){}

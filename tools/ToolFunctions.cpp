#include <QColor>
#include <QImage>
#include "ToolFunctions.h"
#include <iostream>
#include <stack>

// is pixel in bounds
// is area (circle) in bounds
// is area (box) in bounds
// is area (formless) in bounds
//
// is color (safe)
// set color (safe)
//
//
// !!! add const to all reading img->bits() ->constBits()
//
//


bool isInBounds(int width, int height, int x, int y){
    return (x<width && x>=0 && y<height && y>=0);
}

bool isInBounds(QImage* img, int x, int y){
    return isInBounds(img->width(), img->height(), x, y);
}



bool isAreaInBounds(int width, int height, int x, int y, int radius){
    return (x+radius<width && x-radius>=0 && y+radius<height && y-radius>=0);
}

bool isAreaInBounds(QImage* img, int x, int y, int radius){
    return isAreaInBounds(img->width(), img->height(), x, y, radius);
}

bool isAreaInBounds(int width, int height, int x, int y, int boxWidth, int boxHeight){
    return (x+(boxWidth/2.0)<width && x-(boxWidth/2.0)>=0 && y+(boxHeight/2.0)<height && y-(boxHeight/2.0)>=0);
}

bool isAreaInBounds(QImage* img, int x, int y, int boxWidth, int boxHeight){
    return isAreaInBounds(img->width(), img->height(), x, y, boxWidth, boxHeight);
}

bool isAreaInBounds(int width, int height, int x, int y, int left, int right, int up, int down){
    return (x+right<width && x-left>=0 && y-up>=0 && y+down<height);
}

bool isAreaInBounds(QImage* img, int x, int y, int left, int right, int up, int down){
    return isAreaInBounds(img->width(), img->height(), x, y, left, right, up, down);
}



void setColor(QColor color, unsigned char* ptr, int width, int x, int y){
    //std::cout << "C" << std::endl;
    ptr[width*4*y + 4*x + 0] = color.blue();
    ptr[width*4*y + 4*x + 1] = color.green();
    ptr[width*4*y + 4*x + 2] = color.red();
    ptr[width*4*y + 4*x + 3] = color.alpha();
    //std::cout << "D" << std::endl;
}

void setColor(QColor color, QImage* img, int x, int y){
    //std::cout << "B" << std::endl;
    setColor(color, img->bits(), img->width(), x, y);
}

void safeSetColor(QColor color, QImage* img, int x, int y){
    if(!isInBounds(img, x, y))return;
    setColor(color, img, x, y);
}

void safeSetColor(QColor color, unsigned char* ptr, int width, int height, int x, int y){
    if(!isInBounds(width, height, x, y))return;
    setColor(color, ptr, width, x, y);
}

void safeSetColor(QColor color, unsigned char* ptr, int width, int height, int colorPosition){
    int x = colorPosition%width;
    int y = colorPosition/width;
    if(!isInBounds(width, height, x, y))return;
    setColor(color, ptr, width, x, y);
}



bool isColor(unsigned char* ptr, QColor color, int width, int x, int y){
    if(ptr[x*4+width*y*4+0]!=color.red())return false;
    if(ptr[x*4+width*y*4+1]!=color.green())return false;
    if(ptr[x*4+width*y*4+2]!=color.blue())return false;
    if(ptr[x*4+width*y*4+3]!=color.alpha())return false;
    return true;
}

bool isColor(QImage* layer, QColor color, int x, int y){
    return isColor(layer->bits(), color, layer->width(), x, y);
}

bool safeIsColor(QImage* layer, QColor color, int x, int y){
    if(!isInBounds(layer,  x, y))return false;
    return isColor(layer, color, x, y);
}

bool safeIsColor(unsigned char* ptr, QColor color, int width, int height, int x, int y){
    if(!isInBounds(width, height, x, y))return false;
    return isColor(ptr, color, width, x, y);
}

QColor getColor(unsigned char* ptr, int width, int x, int y){
    return QColor(ptr[x*4+width*y*4+0], ptr[x*4+width*y*4+1], ptr[x*4+width*y*4+2], ptr[x*4+width*y*4+3]);
}

QColor getColor(QImage* layer, int x, int y){
    return getColor(layer->bits(), layer->width(), x, y);
}

QColor safeGetColor(unsigned char* ptr, int width, int height, int x, int y){
    if(isInBounds(width, height, x, y)) return getColor(ptr, width, x, y);
    return QColor(0,0,0,0);
}

QColor safeGetColor(QImage* layer, int x, int y){
    return safeGetColor(layer->bits(), layer->width(), layer->height(), x, y);
}


/// CONSTRUCTION ZONE!!! MUCHO GUSTO!!!
/// THERE IS ONLY ONE THING YOU SHOULD KNOW!!!
/// IN THE END IT DOESN'T EVEN MATTER!!!

void stamp(unsigned char* ptr, int width, QColor color, int radius, int cx, int cy){
    for (int y = -radius; y <= radius; y++) for (int x = -radius; x <= radius; x++) if (x*x + y*y <= radius*radius) setColor(color, ptr, width, x+cx, y+cy);
}

void stamp(QImage* layer, QColor color, int radius, int cx, int cy){
    //std::cout << "A" << std::endl;
    for (int y = -radius; y <= radius; y++)for (int x = -radius; x <= radius; x++)if (x*x + y*y <= radius*radius)setColor(color, layer, x+cx, y+cy);
}

void safeStamp(QImage* layer, QColor color, int radius, int cx, int cy){
    if(isAreaInBounds(layer, cx, cy, radius))stamp(layer, color, radius, cx, cy);
    else for(int y=-radius;y<=radius;y++)for(int x=-radius;x<=radius;x++)if(x*x+y*y<=radius*radius)safeSetColor(color,layer,x+cx,y+cy);
}

void safeStamp(unsigned char* ptr, int width, int height, QColor color, int radius, int cx, int cy){
    if(isAreaInBounds(width, height, cx, cy, radius))stamp(ptr, width, color, radius, cx, cy);
    else for(int y=-radius;y<=radius;y++)for(int x=-radius;x<=radius;x++)if(x*x+y*y<=radius*radius)safeSetColor(color, ptr, width, height, x+cx, y+cy);
}


void drawLineBetween(unsigned char* ptr, int width, int height, QColor color, int radius, int sx, int sy, int ex, int ey){
    double a = (ex==sx) ? 0 : (ey-sy)/double(ex-sx);
    double b = ey - ex*a;

    LINETYPE lineType;
    if(sx == ex && sy == ey)lineType = LINETYPE::POINT;
    else if(sx == ex)       lineType = LINETYPE::VERTICAL;
    else if(sy == ey)       lineType = LINETYPE::HORIZONTAL;
    else                    lineType = a*a <= 1 ? LINETYPE::FLAT : LINETYPE::STEEP;

    int xIterator = sx;
    int yIterator = sy;

    switch(lineType){
    case(LINETYPE::POINT):
        safeStamp(ptr, width, height, color, radius, sx, sy);

        break;
    case(LINETYPE::VERTICAL):
        if(sy < ey) for(;yIterator<ey;yIterator++)stamp(ptr, width, color, radius, sx, yIterator);
        else for(;yIterator>sy;yIterator--)stamp(ptr, width, color, radius, sx, yIterator);
        break;
    case(LINETYPE::HORIZONTAL):
        if(sx < ex) for(;xIterator<ex;xIterator++)stamp(ptr, width, color, radius, xIterator, sy);
        else for(;xIterator>ex;xIterator--)stamp(ptr, width, color, radius, xIterator, sy);
        break;
    case(LINETYPE::FLAT):
        if(sx < ex) for(;xIterator<ex;xIterator++)stamp(ptr, width, color, radius, xIterator, valueForArgument(a, b, xIterator));
        else for(;xIterator>ex;xIterator--)stamp(ptr, width, color, radius, xIterator, valueForArgument(a, b, xIterator));
        break;
    case(LINETYPE::STEEP):
        if(sy < ey) for(;yIterator<ey;yIterator++)stamp(ptr, width, color, radius, argumentForValue(a, b, yIterator), yIterator);
        else for(;yIterator>ey;yIterator--)stamp(ptr, width, color, radius, argumentForValue(a, b, yIterator), yIterator);
        break;
    default:
        return;
    }
}

void drawLineBetween(QImage* layer, QColor color, int radius, int sx, int sy, int ex, int ey){
    drawLineBetween(layer->bits(), layer->width(), layer->height(), color, radius, sx, sy, ex, ey);
}

void safeDrawLineBetween(unsigned char* ptr, int width, int height, QColor color, int radius, int sx, int sy, int ex, int ey){
    double a = (ex==sx) ? 0 : (ey-sy)/double(ex-sx);
    double b = ey - ex*a;

    LINETYPE lineType;
    if(sx == ex && sy == ey)lineType = LINETYPE::POINT;
    else if(sx == ex)       lineType = LINETYPE::VERTICAL;
    else if(sy == ey)       lineType = LINETYPE::HORIZONTAL;
    else                    lineType = a*a <= 1 ? LINETYPE::FLAT : LINETYPE::STEEP;

    int xIterator = sx;
    int yIterator = sy;
    switch(lineType){
    case(LINETYPE::POINT):
        safeStamp(ptr, width, height, color, radius, sx, sy);

        break;
    case(LINETYPE::VERTICAL):
        if(sy < ey) for(;yIterator<ey;yIterator++)safeStamp(ptr, width, height, color, radius, sx, yIterator);
        else for(;yIterator>ey;yIterator--)safeStamp(ptr, width, height, color, radius, sx, yIterator);
        break;
    case(LINETYPE::HORIZONTAL):
        if(sx < ex) for(;xIterator<ex;xIterator++)safeStamp(ptr, width, height, color, radius, xIterator, sy);
        else for(;xIterator>ex;xIterator--)safeStamp(ptr, width, height, color, radius, xIterator, sy);
        break;
    case(LINETYPE::FLAT):
        if(sx < ex) for(;xIterator<ex;xIterator++) safeStamp(ptr, width, height, color, radius, xIterator, valueForArgument(a, b, xIterator));
        else for(;xIterator>ex;xIterator--)safeStamp(ptr, width, height, color, radius, xIterator, valueForArgument(a, b, xIterator));
        break;
    case(LINETYPE::STEEP):
        if(sy < ey) for(;yIterator<ey;yIterator++)safeStamp(ptr, width, height, color, radius, argumentForValue(a, b, yIterator), yIterator);
        else for(;yIterator>ey;yIterator--)safeStamp(ptr, width, height, color, radius, argumentForValue(a, b, yIterator), yIterator);
        break;
    default:
        return;
    }
}

void safeDrawLineBetween(QImage* layer, QColor color, int radius, int sx, int sy, int ex, int ey){
    safeDrawLineBetween(layer->bits(), layer->width(), layer->height(), color, radius, sx, sy, ex, ey);
}



double valueForArgument(double a, double b, int x){
    return a*x+b;
}

double argumentForValue(double a, double b, int y){
    return (y-b)/a;
}


void globalFloodFill(QImage* layer, QColor repaintColor, int sx, int sy, int tolerance){
    QColor targetColor = getColor(layer, sx, sy);
    for(int y=0; y<layer->height();y++)for(int x=0; x<layer->width();x++) if(getColor(layer, x, y) == targetColor)setColor(repaintColor, layer, x, y);
}

void floodFill(QImage* layer, QColor repaintColor, int sx, int sy, int tolerance){
    QColor targetColor = getColor(layer, sx, sy);
    if(targetColor==repaintColor)return;
    std::stack<int> a;
    std::vector<bool> visited;
    visited.resize(layer->height()*layer->width());

    a.push(layer->width()*sy+sx);
    visited[a.top()]=true;

    int currentNode;
    int x;
    int y;
    while(!a.empty()){
        currentNode=a.top();
        x=currentNode%layer->width();
        y=currentNode/layer->width();
        a.pop();

        if(!isInBounds(layer, x, y))continue;
        setColor(repaintColor,layer,x,y);

        if(x-1>=0)if(!visited[currentNode-1] && getColor(layer,x-1,y)==targetColor){
                a.push(currentNode-1);
                visited[a.top()]=true;
            }
        if(x+1<layer->width())if(!visited[currentNode+1] && getColor(layer,x+1,y)==targetColor){
                a.push(currentNode+1);
                visited[a.top()]=true;
            }
        if(y-1>=0)if(!visited[currentNode-layer->width()] && getColor(layer,x,y-1)==targetColor){
                a.push(currentNode-layer->width());
                visited[a.top()]=true;
            }
        if(y+1<layer->height())if(!visited[currentNode+layer->width()] && getColor(layer,x,y+1)==targetColor){
                a.push(currentNode+layer->width());
                visited[a.top()]=true;
            }
    }
}


int cursorOffset(int offset, int coordinate){
    return offset+coordinate;
}



void LineTypeDebug(LINETYPE t){
    std::cout << "Line type:";
    if(t==LINETYPE::POINT) std::cout << "POINT" << std::endl;
    if(t==LINETYPE::VERTICAL) std::cout << "VERTICAL" << std::endl;
    if(t==LINETYPE::HORIZONTAL) std::cout << "HORIZONTAL" << std::endl;
    if(t==LINETYPE::FLAT) std::cout << "FLAT" << std::endl;
    if(t==LINETYPE::STEEP) std::cout << "STEEP" << std::endl;
}

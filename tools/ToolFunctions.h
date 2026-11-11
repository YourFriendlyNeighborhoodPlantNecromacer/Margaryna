#ifndef TOOLFUNCTIONS_H
#define TOOLFUNCTIONS_H

enum LINETYPE{
    VERTICAL,   //0
    HORIZONTAL, //1
    STEEP,      //2
    FLAT,       //3
    POINT       //4
};

#include <QColor>
#include <QImage>


bool isInBounds(QImage* img, int x, int y);
bool isInBounds(int width, int height, int x, int y);

bool isAreaInBounds(int width, int height, int x, int y, int radius);
bool isAreaInBounds(QImage* img, int x, int y, int radius);
bool isAreaInBounds(int width, int height, int x, int y, int boxWidth, int boxHeight);
bool isAreaInBounds(QImage* img, int x, int y, int boxWidth, int boxHeight);
bool isAreaInBounds(int width, int height, int x, int y, int left, int right, int up, int down);
bool isAreaInBounds(QImage* img, int x, int y, int left, int right, int up, int down);

void setColor(QColor color, unsigned char* ptr, int width, int x, int y);
void setColor(QColor color, QImage* img, int x, int y);
void safeSetColor(QColor color, QImage* img, int x, int y);
void safeSetColor(QColor color, unsigned char* ptr, int width, int height, int x, int y);
void safeSetColor(QColor color, unsigned char* ptr, int width, int height, int colorPosition);
void setColorWAA(QColor color, unsigned char* ptr, int width, int x, int y);//WithAlphaAccomodations.

bool isColor(QImage* layer, QColor color, int x, int y);
bool isColor(unsigned char* ptr, QColor color, int width, int x, int y);
bool safeIsColor(QImage* layer, QColor color, int x, int y);
bool safeIsColor(unsigned char* ptr, QColor color, int width, int height, int x, int y);

QColor getColor(unsigned char* ptr, int width, int x, int y);
QColor getColor(QImage* layer, int x, int y);
QColor safeGetColor(unsigned char* ptr, int width, int height, int x, int y);
QColor safeGetColor(QImage* layer, int x, int y);

void stamp(unsigned char* ptr, int width, QColor color, int radius, int cx, int cy);
void stamp(QImage* layer, QColor color, int radius, int cx, int cy);

void drawLineBetween(QImage* layer, QColor color, int radius, int sx, int sy, int ex, int ey);
void drawLineBetween(unsigned char* ptr, int width, int height, QColor color, int radius, int sx, int sy, int ex, int ey);
void safeDrawLineBetween(QImage* layer, QColor color, int radius, int sx, int sy, int ex, int ey);
void safeDrawLineBetween(unsigned char* ptr, int width, int height, QColor color, int radius, int sx, int sy, int ex, int ey);

double valueForArgument(double a, double b, int x);
double argumentForValue(double a, double b, int y);

void stamp(QImage* layer, QColor color, int radius, int cx, int cy);
void stamp(unsigned char* ptr, int width, QColor color, int radius, int cx, int cy);
void safeStamp(QImage* layer, QColor color, int radius, int cx, int cy);
void safeStamp(unsigned char* ptr, int width, QColor color, int radius, int cx, int cy);

void globalFloodFill(QImage* layer, QImage* transLayer, QColor repaintColor, int sx, int sy, int tolerance = 0);
void floodFill(QImage* layer, QImage* transLayer, QColor repaintColor, int sx, int sy, int tolerance = 0);

int cursorOffset(int offset, int coordinate);

void applyLayer(QImage* paintedLayer, QImage* sourcesLayer);

void LineTypeDebug(LINETYPE t);
#endif // TOOLFUNCTIONS_H

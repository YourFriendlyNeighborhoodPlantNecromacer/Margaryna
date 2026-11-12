#ifndef TOOL_H
#define TOOL_H

#include <QPoint>
#include <QPainter>

enum TOOLMODE{
    Unselected,
    Shape,
    Draw,
    Fill,
    Select,
    Special
};

enum TOOL{
    NotSet,
    //Shape
    Line,
    CurvedLine,
    CircleOval,
    SquareRectangle,
    EqualsidedPolygon,
    Polygon,
    //Drawing
    Pen,
    Brush,
    //Fill
    Bucket,
    //Select
    Rectangle,
    Lasso,
    MagicWand,
    //Special
    Blackhole,
    Gravity
};

class Tool{
public:

    Tool() = default;
    virtual ~Tool() = default;
    virtual void press(int x, int y) = 0;
    virtual void move(int x, int y) = 0;
    virtual void release(int x, int y) = 0;
    virtual void cancel(){}
    virtual void paintPreview(int x, int y){}
};

#endif // TOOL_H

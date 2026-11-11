#ifndef TOOL_H
#define TOOL_H

#include <QPoint>
#include <QPainter>

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

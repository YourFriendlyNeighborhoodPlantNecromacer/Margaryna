#ifndef FILLTOOL_H
#define FILLTOOL_H

#include "../Tool.h"
#include <QImage>
#include <QColor>


class FillTool : public Tool{
public:
    QImage *selectedLayer;
    QColor color;
    int tolerance;
    bool isGlobal;
    bool active = false;

    FillTool(QImage* img, QColor selected_color = QColor(0, 0, 0), int colorOffsetTolerance=0, bool global=false);

    void press(int x, int y) override;
    void move(int x, int y) override;
    void release(int x, int y) override;
    void cancel() override;
};
#endif // FILLTOOL_H

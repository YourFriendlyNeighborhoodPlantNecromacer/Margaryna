#ifndef TOOLSETTINGS_H
#define TOOLSETTINGS_H
#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QRect>
#include <QColor>
#include <QImage>
#include "../LabeledSlider/LabeledSlider.h"


class ToolSettings : public QGroupBox
{
    Q_OBJECT
private:
    QHBoxLayout* sliderBox;
    LabeledSlider* colorRedPicker;
    LabeledSlider* colorGreenPicker;
    LabeledSlider* colorBluePicker;
    LabeledSlider* colorAlphaPicker;
    QImage* colorPreview;

    LabeledSlider* radiousPicker;

    QColor color;
    int radius;
    bool isFillGlobal;

public:
    ToolSettings(QWidget* parent=nullptr);

    void refreshColor();
    void refreshRadius();
    void refreshAll();
    QColor getColor();
    int getRadius();
};

#endif // TOOLSETTINGS_H

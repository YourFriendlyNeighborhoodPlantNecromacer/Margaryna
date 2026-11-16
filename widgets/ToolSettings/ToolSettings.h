#ifndef TOOLSETTINGS_H
#define TOOLSETTINGS_H
#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QRect>
#include <QColor>
#include <QLabel>
#include <QCheckBox>
#include "../LabeledSlider/LabeledSlider.h"


class ToolSettings : public QGroupBox
{
    Q_OBJECT
private:
    QVBoxLayout* masterBox;

    QWidget* primaryColorWidget;
    QHBoxLayout* primaryColorSliderBoxLayout;
    LabeledSlider* primaryColorRedPicker;
    LabeledSlider* primaryColorGreenPicker;
    LabeledSlider* primaryColorBluePicker;
    LabeledSlider* primaryColorAlphaPicker;
    QLabel* primaryColorPreview;

    QWidget* secondaryColorWidget;
    QHBoxLayout* secondaryColorSliderBoxLayout;
    LabeledSlider* secondaryColorRedPicker;
    LabeledSlider* secondaryColorGreenPicker;
    LabeledSlider* secondaryColorBluePicker;
    LabeledSlider* secondaryColorAlphaPicker;
    QLabel* secondaryColorPreview;

    QWidget* radiusWidget;
    QHBoxLayout* radiusSliderBoxLayout;
    LabeledSlider* radiusPicker;

    QWidget* fillWidget;
    QVBoxLayout* fillModesBoxLayout;
    QCheckBox* isGlobal;

    QWidget* polygonModeWidget;
    QVBoxLayout* polygonModeBoxLayout;
    QCheckBox* fillPolygon;
    QCheckBox* showFinishPolygonLinePreview;
    QCheckBox* showFinishPolygonFillPreview;

    QWidget* shapeModeWidget;
    QVBoxLayout* shapeModeBoxLayout;
    QCheckBox* fillShape;
    QCheckBox* showFinishShapeFillPreview;

public:
    ToolSettings(QWidget* parent=nullptr);
    QColor getPrimaryColor();
    QColor getSecondaryColor();
    int getRadius();

    void showColorSliders();
    void showRadiuSlider();
    void showGlobalFillCheckbox();

    void hideAllWidgets();
    void showPenSettings();
    void showLineSettings();
    void showBucketSettings();
};

#endif // TOOLSETTINGS_H

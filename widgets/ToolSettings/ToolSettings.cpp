#include "ToolSettings.h"

#include <QApplication>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QPainter>
#include <QImage>


ToolSettings::ToolSettings(QWidget* parent) : QGroupBox("Tool Settings", parent){
    masterBox = new QVBoxLayout;



    primaryColorWidget = new QWidget;
    primaryColorSliderBoxLayout = new QHBoxLayout;
    primaryColorPreview = new QLabel(primaryColorWidget);// = new QImage(32, 32, QImage::Format_ARGB32);//change to label, gooberboy
    primaryColorRedPicker = new LabeledSlider(primaryColorWidget);
    primaryColorRedPicker->setLabelText("R");
    primaryColorGreenPicker = new LabeledSlider(primaryColorWidget);
    primaryColorGreenPicker->setLabelText("G");
    primaryColorBluePicker = new LabeledSlider(primaryColorWidget);
    primaryColorBluePicker->setLabelText("B");
    primaryColorAlphaPicker = new LabeledSlider(primaryColorWidget);
    primaryColorAlphaPicker->setLabelText("A");

    primaryColorSliderBoxLayout->addWidget(primaryColorRedPicker);
    primaryColorSliderBoxLayout->addWidget(primaryColorGreenPicker);
    primaryColorSliderBoxLayout->addWidget(primaryColorBluePicker);
    primaryColorSliderBoxLayout->addWidget(primaryColorAlphaPicker);
    primaryColorWidget->setLayout(primaryColorSliderBoxLayout);


    secondaryColorWidget = new QWidget;
    secondaryColorSliderBoxLayout = new QHBoxLayout;
    secondaryColorPreview = new QLabel(secondaryColorWidget);
    secondaryColorRedPicker = new LabeledSlider(secondaryColorWidget);
    secondaryColorRedPicker->setLabelText("R");
    secondaryColorGreenPicker = new LabeledSlider(secondaryColorWidget);
    secondaryColorGreenPicker->setLabelText("G");
    secondaryColorBluePicker = new LabeledSlider(secondaryColorWidget);
    secondaryColorBluePicker->setLabelText("B");
    secondaryColorAlphaPicker = new LabeledSlider(secondaryColorWidget);
    secondaryColorAlphaPicker->setLabelText("A");

    secondaryColorSliderBoxLayout->addWidget(secondaryColorRedPicker);
    secondaryColorSliderBoxLayout->addWidget(secondaryColorGreenPicker);
    secondaryColorSliderBoxLayout->addWidget(secondaryColorBluePicker);
    secondaryColorSliderBoxLayout->addWidget(secondaryColorAlphaPicker);
    secondaryColorWidget->setLayout(secondaryColorSliderBoxLayout);



    radiusWidget = new QWidget;
    radiusSliderBoxLayout = new QHBoxLayout;
    radiusPicker = new LabeledSlider(radiusWidget);
    radiusPicker->setLabelText("r");
    radiusPicker->changeSliderRange(0, 64);

    radiusSliderBoxLayout->addWidget(radiusPicker);
    radiusWidget->setLayout(radiusSliderBoxLayout);


    fillWidget = new QWidget;
    fillModesBoxLayout = new QVBoxLayout(fillWidget);
    isFillGlobal = new QCheckBox(fillWidget);

    fillModesBoxLayout->addWidget(isFillGlobal);
    fillWidget->setLayout(fillModesBoxLayout);


    polygonModeWidget = new QWidget;
    polygonModeBoxLayout = new QVBoxLayout(polygonModeWidget);
    fillPolygon = new QCheckBox(polygonModeWidget);
    showFinishPolygonLinePreview = new QCheckBox(polygonModeWidget);
    showFinishPolygonFillPreview = new QCheckBox(polygonModeWidget);

    polygonModeBoxLayout->addWidget(fillPolygon);
    polygonModeBoxLayout->addWidget(showFinishPolygonLinePreview);
    polygonModeBoxLayout->addWidget(showFinishPolygonFillPreview);
    polygonModeWidget->setLayout(polygonModeBoxLayout);



    shapeModeWidget = new QWidget;
    shapeModeBoxLayout = new QVBoxLayout(shapeModeWidget);
    fillShape = new QCheckBox(shapeModeWidget);

    showFinishShapeFillPreview = new QCheckBox(shapeModeWidget);
    shapeModeWidget->setLayout(shapeModeBoxLayout);



    masterBox->addWidget(primaryColorWidget);
    masterBox->addWidget(secondaryColorWidget);
    masterBox->addWidget(radiusWidget);
    masterBox->addWidget(fillWidget);
    masterBox->addWidget(polygonModeWidget);
    masterBox->addWidget(shapeModeWidget);

    setLayout(masterBox);
    hideAllWidgets();
}

QColor ToolSettings::getPrimaryColor(){
    return QColor(primaryColorRedPicker->getSliderValue(), primaryColorGreenPicker->getSliderValue(), primaryColorBluePicker->getSliderValue(), primaryColorAlphaPicker->getSliderValue());
}

QColor ToolSettings::getSecondaryColor(){
    return QColor(secondaryColorRedPicker->getSliderValue(), secondaryColorGreenPicker->getSliderValue(), secondaryColorBluePicker->getSliderValue(), secondaryColorAlphaPicker->getSliderValue());
}

int ToolSettings::getRadius(){
    return radiusPicker->getSliderValue();
}

bool ToolSettings::getIsBucketGlobal(){
    return isFillGlobal->isChecked();
}

void ToolSettings::hideAllWidgets(){
    primaryColorWidget->hide();
    secondaryColorWidget->hide();
    radiusWidget->hide();
    fillWidget->hide();
    polygonModeWidget->hide();
    shapeModeWidget->hide();
}

void ToolSettings::showPenSettings(){
    hideAllWidgets();
    primaryColorWidget->show();
    radiusWidget->show();
}

void ToolSettings::showLineSettings(){
    hideAllWidgets();
    primaryColorWidget->show();
    radiusWidget->show();
}

void ToolSettings::showBucketSettings(){
    hideAllWidgets();
    primaryColorWidget->show();
    fillWidget->show();
}

void ToolSettings::showCircleOvalSettings(){
    hideAllWidgets();
    primaryColorWidget->show();
    secondaryColorWidget->show();
    radiusWidget->show();
}


//...

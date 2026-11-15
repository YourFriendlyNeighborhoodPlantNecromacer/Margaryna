#include "ToolSettings.h"

#include <QApplication>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QPainter>
#include <iostream>

ToolSettings::ToolSettings(QWidget* parent) : QGroupBox("Tool Settings", parent){
    sliderBox = new QHBoxLayout;
    colorRedPicker = new LabeledSlider(this);
    colorRedPicker->setLabelText("R");
    colorGreenPicker = new LabeledSlider(this);
    colorGreenPicker->setLabelText("G");
    colorBluePicker = new LabeledSlider(this);
    colorBluePicker->setLabelText("B");
    colorAlphaPicker = new LabeledSlider(this);
    colorAlphaPicker->setLabelText("A");
    radiousPicker = new LabeledSlider(this);
    radiousPicker->setLabelText("r");
    radiousPicker->changeSliderRange(0, 64);

    //colorPreview = new QImage(32, 32, QImage::Format_ARGB32);

    sliderBox->addWidget(colorRedPicker);
    sliderBox->addWidget(colorGreenPicker);
    sliderBox->addWidget(colorBluePicker);
    sliderBox->addWidget(colorAlphaPicker);
    sliderBox->addWidget(radiousPicker);

    setLayout(sliderBox);
}

void ToolSettings::refreshColor(){
    color.setRed(colorRedPicker->getSliderValue());
    color.setGreen(colorGreenPicker->getSliderValue());
    color.setBlue(colorBluePicker->getSliderValue());
    color.setAlpha(colorAlphaPicker->getSliderValue());
}

void ToolSettings::refreshRadius(){
    radius = radiousPicker->getSliderValue();
}

void ToolSettings::refreshAll(){
    refreshColor();
    refreshRadius();
}

QColor ToolSettings::getColor(){
    /*
    std::cout << int(colorPreview->bits()[0]) << std::endl;
    colorPreview->fill(color);
    QPainter p(this);
    p.drawImage(32, 32, *colorPreview);
    std::cout << int(colorPreview->bits()[0]) << std::endl;
    */
    refreshColor();
    return color;
}

int ToolSettings::getRadius(){
    refreshRadius();
    return radius;
}

//...

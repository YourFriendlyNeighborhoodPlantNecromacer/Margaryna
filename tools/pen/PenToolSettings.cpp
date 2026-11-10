#include <QSlider>
#include <QHBoxLayout>
#include "PenToolSettings.h"
PenToolSettings::PenToolSettings(QHBoxLayout *toolSettingsBoxLayout){
    QSlider *colorRedPicker = new QSlider();
    QSlider *colorGreenPicker = new QSlider();
    QSlider *colorBluePicker = new QSlider();
    QSlider *colorAlphaPicker = new QSlider();
    QSlider *toolRadious = new QSlider();
    colorRedPicker->setRange(0, 255);
    colorGreenPicker->setRange(0, 255);
    colorBluePicker->setRange(0, 255);
    colorAlphaPicker->setRange(0,255);
    toolRadious->setRange(0,255);
    toolSettingsBoxLayout->addWidget(colorRedPicker);
    toolSettingsBoxLayout->addWidget(colorGreenPicker);
    toolSettingsBoxLayout->addWidget(colorBluePicker);
    toolSettingsBoxLayout->addWidget(colorAlphaPicker);
    toolSettingsBoxLayout->addWidget(toolRadious);
}

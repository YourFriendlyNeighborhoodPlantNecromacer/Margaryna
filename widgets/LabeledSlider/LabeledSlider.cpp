#include "LabeledSlider.h"
#include <QLabel>
#include <QSlider>
#include <QString>
#include <QGroupBox>

LabeledSlider::LabeledSlider(QWidget* parent) : QWidget(parent){
    label = new QLabel(this);
    slider = new QSlider(this);
    slider->setRange(0, 255);
    thing = new QVBoxLayout(this);
    thing->addWidget(label);
    thing->addWidget(slider);

}

void LabeledSlider::changeSliderRange(int min, int max){
    slider->setRange(min, max);
}

void LabeledSlider::setSliderValue(int value){
    slider->setValue(value);
}

int LabeledSlider::getSliderValue(){
    return slider->value();
}

void LabeledSlider::setLabelText(const QString &text){
    label->setText(text);
}

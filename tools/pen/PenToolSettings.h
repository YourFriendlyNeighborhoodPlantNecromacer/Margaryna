#ifndef PENTOOLSETTINGS_H
#define PENTOOLSETTINGS_H


#include <QSlider>
#include <QHBoxLayout>


class PenToolSettings{
public:
    QSlider *colorRedPicker;
    QSlider *colorGreenPicker;
    QSlider *colorBluePicker;
    QSlider *colorAlphaPicker;
    QSlider *toolRadious;
    PenToolSettings(QHBoxLayout *toolSettingsBoxLayout);
};

#endif // PENTOOLSETTINGS_H

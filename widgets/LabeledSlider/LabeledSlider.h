#ifndef LABELEDSLIDER_H
#define LABELEDSLIDER_H

#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QString>


class LabeledSlider : public QWidget
{
    Q_OBJECT
public:
    QLabel* label;
    QSlider* slider;
    QVBoxLayout* thing;
    LabeledSlider(QWidget *parent=nullptr);

    void changeSliderRange(int min, int max);
    void setSliderValue(int value);
    int getSliderValue();
    void setLabelText(const QString &text);
};

#endif // LABELEDSLIDER_H

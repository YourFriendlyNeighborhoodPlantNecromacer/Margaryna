#ifndef TOOLTAB_H
#define TOOLTAB_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QRect>

class ToolTab : public QGroupBox
{
    Q_OBJECT
public:
    QGroupBox* toolBox;
    QHBoxLayout *toolBoxLayout;
    QPushButton *shapeButton;
    QPushButton *drawButton;
    QPushButton *fillButton;
    QPushButton *selectButton;
    QPushButton *specialButton;

    ToolTab(QWidget* parent=nullptr);
};

#endif // TOOLTAB_H

#ifndef TOOLTAB_H
#define TOOLTAB_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QRect>
#include "tools/Tool.h"

class ToolTab : public QGroupBox
{
    Q_OBJECT
public:
    QHBoxLayout *toolBoxLayout;
    QPushButton *shapeButton;
    QPushButton *drawButton;
    QPushButton *fillButton;
    QPushButton *selectButton;
    QPushButton *specialButton;

    ToolTab(QWidget* parent=nullptr);

signals:
    void toolsetSelected(TOOL selectedTool);
};


#endif // TOOLTAB_H

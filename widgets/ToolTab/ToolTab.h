#ifndef TOOLTAB_H
#define TOOLTAB_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QRect>
#include "tools/Tool.h"
#include "../ToolsetButton/ToolsetButton.h"
#include <QMetaEnum>

class ToolTab : public QGroupBox
{
    Q_OBJECT
public:
    QHBoxLayout *toolBoxLayout;
    ToolsetButton *shapeButton;
    ToolsetButton *drawButton;
    ToolsetButton *fillButton;
    ToolsetButton *selectButton;
    ToolsetButton *specialButton;

    ToolTab(QWidget* parent=nullptr);

signals:
    void toolsetSelected(TOOL selectedTool);
};


#endif // TOOLTAB_H

#include "ToolTab.h"
#include <QGroupBox>
#include <QWidget>

ToolTab::ToolTab(QWidget* parent) : QGroupBox(parent){
    toolBoxLayout = new QHBoxLayout;
    shapeButton = new QPushButton("Shape");
    drawButton = new QPushButton("Draw");
    fillButton = new QPushButton("Fill");
    selectButton = new QPushButton("Select");
    specialButton = new QPushButton("Special");

    toolBoxLayout->addWidget(shapeButton);
    toolBoxLayout->addWidget(drawButton);
    toolBoxLayout->addWidget(fillButton);
    toolBoxLayout->addWidget(selectButton);
    toolBoxLayout->addWidget(specialButton);

    //Whoever invented lambdas should be counted as one of the TOOLs
    connect(shapeButton,&QPushButton::clicked,this,[this](){emit this->toolsetSelected(TOOL::Line);});
    connect(drawButton,&QPushButton::clicked,this,[this](){emit this->toolsetSelected(TOOL::Pen);});
    connect(fillButton, &QPushButton::pressed, this, [this](){emit this->toolsetSelected(TOOL::Bucket);});
    connect(selectButton,&QPushButton::clicked,this,[this](){emit this->toolsetSelected(TOOL::Lasso);});
    connect(specialButton,&QPushButton::clicked,this,[this](){emit this->toolsetSelected(TOOL::Gravity);});
    setLayout(toolBoxLayout);
}

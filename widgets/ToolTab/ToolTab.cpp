#include "ToolTab.h"
#include <QGroupBox>
#include <QWidget>
#include <iostream>


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
    connect(shapeButton,SIGNAL(clicked()),parent,SLOT(slot_shape()));
    connect(drawButton,SIGNAL(clicked()),parent,SLOT(slot_draw()));
    connect(fillButton,SIGNAL(clicked()),parent,SLOT(slot_fill()));
    connect(selectButton,SIGNAL(clicked()),parent,SLOT(slot_select()));
    connect(specialButton,SIGNAL(clicked()),parent,SLOT(slot_special()));
    std::cout << "ABBA" << std::endl;
    setLayout(toolBoxLayout);
}

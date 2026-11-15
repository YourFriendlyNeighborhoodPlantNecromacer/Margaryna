#include "ToolTab.h"
#include <QGroupBox>
#include "../ToolsetButton/ToolsetButton.h"
#include <QWidget>


ToolTab::ToolTab(QWidget* parent) : QGroupBox(parent){
    std::vector<std::vector<std::pair<QString, TOOL>>> dic(5);//Przeraszam za to, czym to się stanie.
    dic[0] = {std::pair("Line", TOOL::Line), std::pair("CurvedLine", TOOL::CurvedLine), std::pair("CircleOval", TOOL::CircleOval), std::pair("Square", TOOL::SquareRectangle), std::pair("Equalsided Polygon", TOOL::EqualsidedPolygon), std::pair("Polygon", TOOL::Polygon)};
    dic[1] = {std::pair("Pen", TOOL::Pen), std::pair("Brush", TOOL::Brush)};
    dic[2] = {std::pair("bucket", TOOL::Bucket)};
    dic[3] = {std::pair("Lasso", TOOL::Lasso)};
    dic[4] = {std::pair("Blackhole", TOOL::Blackhole)};

    toolBoxLayout = new QHBoxLayout;
    shapeButton = new ToolsetButton(this, dic[0], "Shape");
    shapeButton->currentDefaultTool = TOOL::Line;
    drawButton = new ToolsetButton(this, dic[1], "Draw");
    shapeButton->currentDefaultTool = TOOL::Pen;
    fillButton = new ToolsetButton(this, dic[2], "Fill");
    shapeButton->currentDefaultTool = TOOL::Bucket;
    selectButton = new ToolsetButton(this, dic[3], "Select");
    shapeButton->currentDefaultTool = TOOL::Lasso;
    specialButton = new ToolsetButton(this, dic[4], "Special");
    shapeButton->currentDefaultTool = TOOL::Gravity;

    toolBoxLayout->addWidget(shapeButton);
    toolBoxLayout->addWidget(drawButton);
    toolBoxLayout->addWidget(fillButton);
    toolBoxLayout->addWidget(selectButton);
    toolBoxLayout->addWidget(specialButton);

    //Whoever invented lambdas should be counted as one of the TOOLs
    connect(shapeButton,&ToolsetButton::toolSelected,this, &ToolTab::toolsetSelected);//WHat should i put here???
    connect(drawButton,&ToolsetButton::toolSelected,this, &ToolTab::toolsetSelected);
    connect(fillButton, &ToolsetButton::toolSelected, this, &ToolTab::toolsetSelected);
    connect(selectButton,&ToolsetButton::toolSelected,this, &ToolTab::toolsetSelected); // currently causing crash but that is okay
    connect(specialButton,&ToolsetButton::toolSelected,this, &ToolTab::toolsetSelected);// currently causing crash but that is okay
    setLayout(toolBoxLayout);
}

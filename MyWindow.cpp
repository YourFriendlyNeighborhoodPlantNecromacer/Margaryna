#include "MyWindow.h"
#include <iostream>
#include "tools/ToolFunctions.h"
#include <QVBoxLayout>
#include "tools/Tool.h"
#include "tools/fill/FillTool.h"
#include "tools/line/LineTool.h"
#include "tools/pen/PenTool.h"
#include "tools/ToolFunctions.h"
#include "widgets/LabeledSlider.h"
//#include "tools/pen/PenToolSettings.h"

MyWindow::MyWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("I love art");
    resize(800,700);
    width = 600;
    height = 600;
    startX = 10;
    startY = 50;

    img = new QImage(width,height,QImage::Format_ARGB32);
    toolPreviewLayer = new QImage(width,height,QImage::Format_ARGB32);

    currentTool = nullptr;
    lastSelectedTool = TOOL::NotSet;

    //Gen. stuff tab (exit, new drawing, load image in)
    appSettings = new QGroupBox("Controls",this);
    appSettings->setGeometry(QRect(startX+width+startX,0,800-width-2*startX,startY+100));
    boxLayout = new QVBoxLayout;
    cleanButton = new QPushButton("Clense");
    exitButton = new QPushButton("Exit");
    boxLayout->addWidget(cleanButton);
    boxLayout->addWidget(exitButton);
    appSettings->setLayout(boxLayout);
    connect(exitButton,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(cleanButton,SIGNAL(clicked()),this,SLOT(slot_clean()));

    //Tools tab
    toolGroup = new QGroupBox(this);
    toolGroup->setGeometry(QRect(startX,0,width-startX,50));
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
    connect(shapeButton,SIGNAL(clicked()),this,SLOT(slot_shape()));
    connect(drawButton,SIGNAL(clicked()),this,SLOT(slot_draw()));
    connect(fillButton,SIGNAL(clicked()),this,SLOT(slot_fill()));
    connect(selectButton,SIGNAL(clicked()),this,SLOT(slot_select()));
    connect(specialButton,SIGNAL(clicked()),this,SLOT(slot_special()));
    toolGroup->setLayout(toolBoxLayout);

    //Tool settigns tab
    toolSettings = new QGroupBox("Tool Settings", this);
    toolSettings->setGeometry(QRect(startX+width+startX,startY+100,800-width-2*startX,startY+100));
    sliderBox = new QHBoxLayout;
    colorRedPicker = new LabeledSlider(toolSettings);
    colorRedPicker->setLabelText("R");
    colorGreenPicker = new LabeledSlider(toolSettings);
    colorGreenPicker->setLabelText("G");
    colorBluePicker = new LabeledSlider(toolSettings);
    colorBluePicker->setLabelText("B");
    colorAlphaPicker = new LabeledSlider(toolSettings);
    colorAlphaPicker->setLabelText("A");
    radiousPicker = new LabeledSlider(toolSettings);
    radiousPicker->setLabelText("r");
    radiousPicker->changeSliderRange(0, 64);
    sliderBox->addWidget(colorRedPicker);
    sliderBox->addWidget(colorGreenPicker);
    sliderBox->addWidget(colorBluePicker);
    sliderBox->addWidget(colorAlphaPicker);
    sliderBox->addWidget(radiousPicker);

    toolSettings->setLayout(sliderBox);
}

MyWindow::~MyWindow(){
    delete img;
    delete currentTool;
    delete toolPreviewLayer;
}

void MyWindow::paintEvent(QPaintEvent*){
    QPainter p(this);
    p.drawImage(startX,startY,*img);
    p.drawImage(startX,startY,*toolPreviewLayer);
}


void MyWindow::slot_clean(){
    clean();
    update();
}

void MyWindow::clean(){
    for(int y=0; y<height; y++) for(int x=0; x<width; x++) setColor(QColor(255,255,255,0), img->bits(), width, x, y); // BREAD!
}

void MyWindow::mousePressEvent(QMouseEvent *event){
    currentColor = QColor(colorRedPicker->slider->value(), colorGreenPicker->slider->value(), colorBluePicker->slider->value());
    if(lastSelectedTool == TOOL::NotSet && !currentTool)return;
    if(!currentTool)reenableTool();
    if(currentTool)currentTool->press(cursorOffset(-startX, event->x()), cursorOffset(-startY, event->y()));
    update();
}

void MyWindow::mouseMoveEvent(QMouseEvent *event){
    if(currentTool)currentTool->move(cursorOffset(-startX, event->x()), cursorOffset(-startY, event->y()));
    update();
}

void MyWindow::mouseReleaseEvent(QMouseEvent *event){
    if(currentTool)currentTool->release(cursorOffset(-startX, event->x()), cursorOffset(-startY, event->y()));
    delete currentTool;
    currentTool = nullptr;
    update();
}

void MyWindow::slot_shape(){
    if(currentTool)delete currentTool;
    currentTool = new LineTool(img, toolPreviewLayer, QColor(currentColor.red(), currentColor.green(), currentColor.blue()), radiousPicker->slider->value());
    lastSelectedTool = TOOL::Line;
}

void MyWindow::slot_draw(){
    if(currentTool)delete currentTool;
    currentColor = QColor(colorRedPicker->slider->value(), colorGreenPicker->slider->value(), colorBluePicker->slider->value());
    currentTool = new PenTool(img, radiousPicker->slider->value(), QColor(currentColor.red(), currentColor.green(), currentColor.blue()));
    lastSelectedTool = TOOL::Pen;
}

void MyWindow::slot_fill(){
    if(currentTool)delete currentTool;
    currentColor = QColor(colorRedPicker->slider->value(), colorGreenPicker->slider->value(), colorBluePicker->slider->value());
    currentTool = new FillTool(img, currentColor);
    lastSelectedTool = TOOL::Bucket;
}

void MyWindow::slot_select(){
    //currentTool = new Tool();
}

void MyWindow::slot_special(){
    //currentTool = new Tool();
}

void MyWindow::reenableTool(){
    if(currentTool)delete currentTool;
    if(lastSelectedTool==TOOL::Pen)currentTool = new PenTool(img, radiousPicker->slider->value(), currentColor);
    if(lastSelectedTool==TOOL::Line)currentTool = new LineTool(img, toolPreviewLayer, currentColor, radiousPicker->slider->value());
    if(lastSelectedTool==TOOL::Bucket)currentTool = new FillTool(img, currentColor);
}

#include "MyWindow.h"
#include <iostream>
#include "tools/ToolFunctions.h"
#include <QVBoxLayout>
#include "tools/Tool.h"
#include "tools/fill/FillTool.h"
#include "tools/line/LineTool.h"
#include "tools/pen/PenTool.h"
#include "tools/ToolFunctions.h"
#include "widgets/AppSettings/AppSettings.h"
#include "widgets/LabeledSlider/LabeledSlider.h"
//#include "tools/pen/PenToolSettings.h"

MyWindow::MyWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("I love art");
    resize(810,700);
    width = 600;
    height = 600;
    startX = 10;
    startY = 50;

    img = new QImage(width,height,QImage::Format_ARGB32);
    toolPreviewLayer = new QImage(width,height,QImage::Format_ARGB32);
    toolAlphaLayer = new QImage(width,height,QImage::Format_ARGB32);
    img->fill(Qt::white);
    toolPreviewLayer->fill(Qt::transparent);
    toolAlphaLayer->fill(Qt::transparent);

    currentTool = nullptr;
    lastSelectedTool = TOOL::NotSet;

    //Gen. stuff tab (exit, new drawing, load image in)
    appSettings = new AppSettings(this);
    appSettings->setGeometry(QRect(startX+width+startX,0,800-width-2*startX,startY+100));
    connect(appSettings, &AppSettings::cleanRequested, this, &MyWindow::slot_clean);

    //Tools tab
    toolTab = new ToolTab(this);
    toolTab->setGeometry(QRect(startX,0,width-startX,50));

    //Tool settigns tab
    toolSettings = new ToolSettings(this);
    toolSettings->setGeometry(QRect(startX+width+startX,startY+100,800-width-2*startX,startY+100));

}

MyWindow::~MyWindow(){
    delete img;
    delete currentTool;
    delete toolAlphaLayer;
    delete toolPreviewLayer;
}

void MyWindow::paintEvent(QPaintEvent*){
    QPainter p(this);
    p.drawImage(startX,startY,*img);
    p.drawImage(startX,startY,*toolAlphaLayer);
    p.drawImage(startX,startY,*toolPreviewLayer);
}


void MyWindow::clean(){
    for(int y=0; y<height; y++) for(int x=0; x<width; x++) setColor(QColor(255,255,255,255), img->bits(), width, x, y); // BREAD!
}

void MyWindow::mousePressEvent(QMouseEvent *event){
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


void MyWindow::slot_clean(){
    std::cout << "slot_clean()" << std::endl;
    clean();
    update();
}

void MyWindow::slot_shape(){
    if(currentTool)delete currentTool;
    currentTool = new LineTool(img, toolAlphaLayer, toolPreviewLayer, toolSettings->getColor(), toolSettings->getRadius());
    lastSelectedTool = TOOL::Line;
}

void MyWindow::slot_draw(){
    if(currentTool)delete currentTool;
    currentTool = new PenTool(img, toolAlphaLayer, toolSettings->getRadius(), toolSettings->getColor());
    lastSelectedTool = TOOL::Pen;
}

void MyWindow::slot_fill(){
    std::cout << "Bucket tool selected" << std::endl;
    if(currentTool)delete currentTool;
    currentTool = new FillTool(img, toolAlphaLayer, toolSettings->getColor());
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
    if(lastSelectedTool==TOOL::Pen)currentTool = new PenTool(img, toolAlphaLayer, toolSettings->getRadius(), toolSettings->getColor());
    if(lastSelectedTool==TOOL::Line)currentTool = new LineTool(img, toolAlphaLayer, toolPreviewLayer, toolSettings->getColor(), toolSettings->getRadius());
    if(lastSelectedTool==TOOL::Bucket)currentTool = new FillTool(img, toolAlphaLayer, toolSettings->getColor());
}

#include "ToolsetButton.h"
#include <QPushButton>
#include <QWidget>
#include <QMenu>
#include <QString>
#include <QVariant>

ToolsetButton::ToolsetButton(QWidget* parent, std::vector<std::pair<QString, TOOL>> &tools, const QString toolsetName) : QPushButton(parent) {
    toolMenu = new QMenu(this);
    this->setText(toolsetName);
    QAction* a;
    for(unsigned long i=0; i<tools.size();i++){
        a = toolMenu->addAction(tools[i].first);
        a->setData(int(tools[i].second));
    }
    currentDefaultTool = tools[0].second;

    connect(toolMenu,&QMenu::triggered,this, [this](QAction* a){emit toolSelected(TOOL(a->data().toInt()));});
    connect(this,&QPushButton::clicked,this, [this](){emit toolSelected(currentDefaultTool); toolMenu->popup(this->pos());});
}

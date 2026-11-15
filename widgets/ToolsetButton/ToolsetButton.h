#ifndef TOOLSETBUTTON_H
#define TOOLSETBUTTON_H
#include <QPushButton>
#include <QWidget>
#include <QMenu>
#include "tools/Tool.h"

class ToolsetButton : public QPushButton
{
    Q_OBJECT
public:
    TOOL currentDefaultTool;
    QMenu* toolMenu;
    ToolsetButton(QWidget* parent, std::vector<std::pair<QString, TOOL>> &tools, const QString toolsetName);
signals:
    void toolSelected(TOOL selectedTool);
};

#endif // TOOLSETBUTTON_H

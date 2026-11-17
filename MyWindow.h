#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QSlider>
#include <tools/Tool.h>
#include "widgets/AppSettings/AppSettings.h"
#include "widgets/ToolTab/ToolTab.h"
#include "widgets/ToolSettings/ToolSettings.h"

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    MyWindow(QWidget *parent = 0);

    ~MyWindow();

private:
    QImage *img;
    QImage *toolAlphaLayer;
    QImage *toolPreviewLayer;

    AppSettings* appSettings;
    ToolSettings* toolSettings;
    ToolTab* toolTab;

    Tool* currentTool;
    TOOL lastSelectedTool;


    int width;
    int height;
    int startX;
    int startY;
    void clean();
    void shape(int x, int y);
    void draw(int x, int y);
    void fill(int x, int y);
    void select(int x, int y);
    void special(int x, int y);

    bool isToolSet();
    bool wasAnyToolSet();

    void toolStateMenager(int x, int y);
    bool getTool();
private slots:
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void slot_clean();
    void slot_getTool(TOOL selectedTool);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void reenableTool();

};


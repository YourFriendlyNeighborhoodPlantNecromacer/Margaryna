#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QSlider>
#include <tools/Tool.h>
#include "tools/pen/PenToolSettings.h"
#include "widgets/LabeledSlider.h"

enum TOOLMODE{
    Unselected,
    Shape,
    Draw,
    Fill,
    Select,
    Special
};

enum TOOL{
    NotSet,
    //Shape
    Line,
    CurvedLine,
    CircleOval,
    SquareRectangle,
    EqualsidedPolygon,
    Polygon,
    //Drawing
    Pen,
    Brush,
    //Fill
    Bucket,
    //Select
    Rectangle,
    Lasso,
    MagicWand,
    //Special
    Blackhole,
    Gravity
};

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    MyWindow(QWidget *parent = 0);

    ~MyWindow();

private:
    QImage *img;
    QImage *toolPreviewLayer;

    QPushButton *cleanButton;
    QPushButton *exitButton;
    QGroupBox *appSettings;

    QPushButton *shapeButton;
    QPushButton *drawButton;
    QPushButton *fillButton;
    QPushButton *selectButton;
    QPushButton *specialButton;
    QGroupBox *toolGroup;

    Tool* currentTool;
    TOOL lastSelectedTool = TOOL::NotSet;

    QVBoxLayout *boxLayout;
    QHBoxLayout *toolBoxLayout;

    QHBoxLayout* sliderBox;
    LabeledSlider* colorRedPicker;
    LabeledSlider* colorGreenPicker;
    LabeledSlider* colorBluePicker;
    LabeledSlider* colorAlphaPicker;
    LabeledSlider* radiousPicker;

    QGroupBox *toolSettings;
    //PenToolSettings penSettings;


    QColor currentColor;
    int radious;

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

    void toolStateMenager(int x, int y);
private slots:
    void slot_clean();
    void slot_shape();
    void slot_draw();
    void slot_fill();
    void slot_select();
    void slot_special();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent*);
    void reenableTool();
};


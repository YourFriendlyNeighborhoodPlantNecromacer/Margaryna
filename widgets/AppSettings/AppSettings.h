#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QGroupBox>
#include <QPushButton>
#include <QBoxLayout>
#include <QWidget>

class AppSettings : public QGroupBox
{
    Q_OBJECT
public:
    QVBoxLayout *layout;

    AppSettings(QWidget* parent=nullptr);

signals:
    void cleanRequested();

private:
    QPushButton *cleanButton;
    QPushButton *exitButton;
};

#endif // APPSETTINGS_H

/*
 *  appSettings = new QGroupBox("Controls",this);
    appSettings->setGeometry(QRect(startX+width+startX,0,800-width-2*startX,startY+100));
    boxLayout = new QVBoxLayout;
    cleanButton = new QPushButton("Clense");
    exitButton = new QPushButton("Exit");
    boxLayout->addWidget(cleanButton);
    boxLayout->addWidget(exitButton);
    appSettings->setLayout(boxLayout);
    connect(exitButton,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(cleanButton,SIGNAL(clicked()),this,SLOT(slot_clean()));
*/

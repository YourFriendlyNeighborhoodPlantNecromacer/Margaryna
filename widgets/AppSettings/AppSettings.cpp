#include "AppSettings.h"

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <iostream>

//QVBoxLayout *settingBoxLayout

AppSettings::AppSettings(QWidget* parent) : QGroupBox("Controls", parent) {
    cleanButton = new QPushButton("Clense", this);
    exitButton = new QPushButton("Exit", this);

    layout = new QVBoxLayout(this);
    layout->addWidget(cleanButton);
    layout->addWidget(exitButton);

    connect(cleanButton,&QPushButton::clicked,this,&AppSettings::cleanRequested);
    connect(exitButton,&QPushButton::clicked,qApp,&QApplication::quit);
}

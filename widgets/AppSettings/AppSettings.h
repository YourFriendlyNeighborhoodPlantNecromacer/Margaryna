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


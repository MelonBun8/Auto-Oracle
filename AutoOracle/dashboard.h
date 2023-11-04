#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QtWidgets>
#include <QPropertyAnimation>


namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

public slots:
    void expandRightWithAnimation();
    void expandLeftWithAnimation();

private:
    Ui::Dashboard *ui;
    QPropertyAnimation *leftWidgetAnimation;
    QPropertyAnimation *rightWidgetAnimation;
    QPropertyAnimation *stackWidgetAnimation;

};

#endif // DASHBOARD_H

#include "mainwindow.h"
#include "newindow1.h"
#include "./ui_newindow1.h"
#include "./ui_mainwindow.h"
#include <QPropertyAnimation>
<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include <QEasingCurve>
=======
#include <QTimer>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
>>>>>>> Stashed changes
=======
#include <QTimer>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
>>>>>>> Stashed changes


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

<<<<<<< Updated upstream
<<<<<<< Updated upstream
//    QPropertyAnimation *animation = new QPropertyAnimation(ui->label_3, "geometry");
//    animation->setDuration(3000);
//    animation->setStartValue(QRect(530, 0, 0, 0));
//    animation->setEndValue(QRect(530, 80, 111, 91));
//    animation->setEasingCurve(QEasingCurve::InOutQuad);
//    animation->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->label, "geometry");
    animation2->setDuration(3000);
    animation2->setStartValue(QRect(420, 560, 0, 0));
    animation2->setEndValue(QRect(420, 60, 591, 91));
=======
    QTimer* timer = new QTimer(this);

        // Connect the timer to a slot that toggles the stacking order
        connect(timer, &QTimer::timeout, this, &MainWindow::toggleStackingOrder);

        // Set the animation interval (time between bringToFront and sendToBack)
        timer->start(500);



    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->label, "geometry");
    animation2->setDuration(3000);
    animation2->setStartValue(QRect(430, 700, 0, 0));
    animation2->setEndValue(QRect(430, 150, 831, 91));
>>>>>>> Stashed changes
=======
    QTimer* timer = new QTimer(this);

        // Connect the timer to a slot that toggles the stacking order
        connect(timer, &QTimer::timeout, this, &MainWindow::toggleStackingOrder);

        // Set the animation interval (time between bringToFront and sendToBack)
        timer->start(500);



    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->label, "geometry");
    animation2->setDuration(3000);
    animation2->setStartValue(QRect(430, 700, 0, 0));
    animation2->setEndValue(QRect(430, 150, 831, 91));
>>>>>>> Stashed changes
    animation2->setEasingCurve(QEasingCurve::InOutQuad);
    animation2->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *animation3 = new QPropertyAnimation(ui->label_2, "geometry");
    animation3->setDuration(3000);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    animation3->setStartValue(QRect(550, 560, 0, 0));
    animation3->setEndValue(QRect(550, 110, 399, 91));
=======
    animation3->setStartValue(QRect(540, 725, 0, 0));
    animation3->setEndValue(QRect(540, 240, 491, 41));
>>>>>>> Stashed changes
    animation3->setEasingCurve(QEasingCurve::InOutQuad);
    animation3->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *animation5 = new QPropertyAnimation(ui->label_6, "pos");
    animation5->setDuration(25000); // 25 seconds
<<<<<<< Updated upstream
    animation5->setStartValue(QPoint(width(), height() / 2+ 50));
    animation5->setEndValue(QPoint(-ui->label_6->width(), height() / 2 +50));
=======
    animation3->setStartValue(QRect(540, 725, 0, 0));
    animation3->setEndValue(QRect(540, 240, 491, 41));
    animation3->setEasingCurve(QEasingCurve::InOutQuad);
    animation3->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *animation5 = new QPropertyAnimation(ui->label_6, "pos");
    animation5->setDuration(25000); // 25 seconds
    animation5->setStartValue(QPoint(width(), height() / 2 -100));
    animation5->setEndValue(QPoint(-ui->label_6->width(), height() / 2-100));
>>>>>>> Stashed changes
=======
    animation5->setStartValue(QPoint(width(), height() / 2 -100));
    animation5->setEndValue(QPoint(-ui->label_6->width(), height() / 2-100));
>>>>>>> Stashed changes
    animation5->setEasingCurve(QEasingCurve::Linear);
    animation5->setLoopCount(-1); // Loop indefinitely

    // Start the animation
    animation5->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes
void MainWindow::toggleStackingOrder() {
    if (ui->label_5->isHidden() && ui->label_7->isHidden() && ui->label_8->isHidden()) {
        // Make the label visible and bring it to the front
        ui->label_5->show();
        ui->label_5->raise();
        ui->label_7->show();
        ui->label_7->raise();
        ui->label_8->show();
        ui->label_8->raise();
    } else {
        // Hide the label and send it to the back
        ui->label_5->hide();
        ui->label_5->lower();
        ui->label_7->hide();
        ui->label_7->lower();
        ui->label_8->hide();
        ui->label_8->lower();
    }
}

<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
void MainWindow::showNewWindow()
{
    Newindow1 *newWindow = new Newindow1;
    newWindow->show();
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    showNewWindow();
}


#include "dashboard.h"
#include "./ui_dashboard.h"
#include <QPropertyAnimation>
#include <QPainter>
#include <QPushButton>
#include <QPalette>


Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->pushButton_3->setStyleSheet("background-color: #9141d9; border: none; color: #ffffff;");
    ui->pushButton_5->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
    ui->pushButton_4->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
    ui->widget->setMaximumWidth(0);
    ui->widget_2->setMaximumWidth(0);
    ui->stackedWidget->setMaximumWidth(1540);
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_2->setGeometry(1340,20,101,41);

    // Initialize the animations
    leftWidgetAnimation = new QPropertyAnimation(ui->widget,"maximumWidth");
    leftWidgetAnimation->setDuration(500); // Animation duration in milliseconds
    rightWidgetAnimation = new QPropertyAnimation(ui->widget_2, "maximumWidth");
    rightWidgetAnimation->setDuration(500); // Animation duration in milliseconds
    stackWidgetAnimation = new QPropertyAnimation(ui->stackedWidget, "maximumWidth");
    stackWidgetAnimation->setDuration(500); // Animation duration in milliseconds

    QObject::connect(ui->pushButton_3, &QPushButton::clicked, [&]() {
        ui->pushButton_3->setStyleSheet("background-color: #9141d9; border: none; color: #ffffff;");
        ui->pushButton_4->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_5->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->stackedWidget->setCurrentIndex(0);
    });

    QObject::connect(ui->pushButton_4, &QPushButton::clicked, [&]() {
        ui->pushButton_4->setStyleSheet("background-color: #9141d9; border: none; color: #ffffff;");
        ui->pushButton_3->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_5->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->stackedWidget->setCurrentIndex(1);
    });

    //purple #9141d9 blue #263173 white #ffffff
    QObject::connect(ui->pushButton_5, &QPushButton::clicked, [&]() {
        ui->pushButton_5->setStyleSheet("background-color: #9141d9; border: none; color: #ffffff;");
        ui->pushButton_3->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_4->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->stackedWidget->setCurrentIndex(2);
    });


    connect(ui->pushButton, &QPushButton::clicked, this, &Dashboard::expandLeftWithAnimation);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Dashboard::expandRightWithAnimation);

}
// 1540 same, 1340 = 1290 , 1140 = 1090
void Dashboard::expandLeftWithAnimation() {

    if (ui->widget->maximumWidth() == 0 && ui->widget_2->maximumWidth() == 0) {

        leftWidgetAnimation->setStartValue(0);
        leftWidgetAnimation->setEndValue(250);
        leftWidgetAnimation->start();

        stackWidgetAnimation->setStartValue(1540);
        stackWidgetAnimation->setEndValue(1290);
        stackWidgetAnimation->start();
        ui->pushButton_2->setGeometry(1150,20,101,41);
    }
    else if (ui->widget->maximumWidth() == 0 && ui->widget_2->maximumWidth() != 0) {

        leftWidgetAnimation->setStartValue(0);
        leftWidgetAnimation->setEndValue(250);
        leftWidgetAnimation->start();

        stackWidgetAnimation->setStartValue(1290);
        stackWidgetAnimation->setEndValue(1090);
        stackWidgetAnimation->start();
        ui->pushButton_2->setGeometry(950,20,101,41);
    }
    else if(ui->widget->maximumWidth()!=0 && ui->widget_2->maximumWidth()==0)
    {

        leftWidgetAnimation->setStartValue(250);
        leftWidgetAnimation->setEndValue(0);
        leftWidgetAnimation->start();

        stackWidgetAnimation->setStartValue(1290);
        stackWidgetAnimation->setEndValue(1540);
        stackWidgetAnimation->start();
        ui->pushButton_2->setGeometry(1290,20,101,41);
    }
    else {

        ui->pushButton_2->setGeometry(1150,20,101,41);
        leftWidgetAnimation->setStartValue(250);
        leftWidgetAnimation->setEndValue(0);
        leftWidgetAnimation->start();

        stackWidgetAnimation->setStartValue(1090);
        stackWidgetAnimation->setEndValue(1290);
        stackWidgetAnimation->start();

    }

}

void Dashboard::expandRightWithAnimation() {
    if (ui->widget->maximumWidth()!=0 && ui->widget_2->maximumWidth() == 0) {

        rightWidgetAnimation->setStartValue(0);
        rightWidgetAnimation->setEndValue(250);
        rightWidgetAnimation->start();
        stackWidgetAnimation->setStartValue(1290);
        stackWidgetAnimation->setEndValue(1090);
        stackWidgetAnimation->start();
        ui->pushButton_2->setGeometry(950,20,101,41);

    } else if(ui->widget->maximumWidth()!=0 && ui->widget_2->maximumWidth()!=0){

        ui->pushButton_2->setGeometry(1150,20,101,41);
        rightWidgetAnimation->setStartValue(250);
        rightWidgetAnimation->setEndValue(0);
        rightWidgetAnimation->start();
        stackWidgetAnimation->setStartValue(1090);
        stackWidgetAnimation->setEndValue(1290);
        stackWidgetAnimation->start();

    }
    else if(ui->widget->maximumWidth()==0 && ui->widget_2->maximumWidth()==0){

        rightWidgetAnimation->setStartValue(0);
        rightWidgetAnimation->setEndValue(250);
        rightWidgetAnimation->start();
        stackWidgetAnimation->setStartValue(1540);
        stackWidgetAnimation->setEndValue(1290);
        stackWidgetAnimation->start();
        ui->pushButton_2->setGeometry(1150,30,101,41);

        }
    else{

        ui->pushButton_2->setGeometry(1290,20,101,41);
        rightWidgetAnimation->setStartValue(250);
        rightWidgetAnimation->setEndValue(0);
        rightWidgetAnimation->start();
        stackWidgetAnimation->setStartValue(1290);
        stackWidgetAnimation->setEndValue(1540);
        stackWidgetAnimation->start();
        }
}


Dashboard::~Dashboard()
{
    delete ui;
}

/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_5;
    QLabel *label_7;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_8;
    QWidget *page_2;
    QLabel *label_3;
    QWidget *page_3;
    QLabel *label_4;
    QWidget *widget_2;
    QLabel *label;
    QLabel *label_6;

    void setupUi(QMainWindow *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(1540, 800);
        Dashboard->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 59);"));
        centralwidget = new QWidget(Dashboard);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(250, 800));
        widget->setStyleSheet(QString::fromUtf8(""));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(-20, 60, 261, 71));
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 65, 217);\n"
"color: rgb(255, 255, 255);"));
        pushButton_3->setAutoDefault(false);
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(-20, 160, 261, 71));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 49, 115);\n"
"color: rgb(255, 255, 255);"));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(-20, 260, 261, 71));
        pushButton_5->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(0, 0, 255);"));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(-30, -30, 271, 831));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/side bar-PhotoRoom.png")));
        label_5->setScaledContents(true);
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 10, 131, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(45, 65, 124);"));
        label_5->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        label_7->raise();

        horizontalLayout->addWidget(widget);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMaximumSize(QSize(1040, 800));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 59);"));
        page = new QWidget();
        page->setObjectName("page");
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 50, 41, 41));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/menu-bar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(80, 30));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(940, 50, 51, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/profile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(80, 30));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 210, 131, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 0, 171, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 200, 191, 41));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 180, 131, 81));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page_3);

        horizontalLayout->addWidget(stackedWidget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMaximumSize(QSize(250, 800));
        widget_2->setSizeIncrement(QSize(0, 0));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(39, 0, 58);"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 90, 171, 21));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(142, 68, 217);"));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(-18, -21, 301, 821));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/side bar-PhotoRoom.png")));
        label_6->setScaledContents(true);
        label_6->raise();
        label->raise();

        horizontalLayout->addWidget(widget_2);

        Dashboard->setCentralWidget(centralwidget);

        retranslateUi(Dashboard);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QMainWindow *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "MainWindow", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dashboard", "Home", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dashboard", "Search Car", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Dashboard", "Become a Seller", nullptr));
        label_5->setText(QString());
        label_7->setText(QCoreApplication::translate("Dashboard", "AutoOracle", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_2->setText(QCoreApplication::translate("Dashboard", "Home page", nullptr));
        label_8->setText(QCoreApplication::translate("Dashboard", "Dashboard", nullptr));
        label_3->setText(QCoreApplication::translate("Dashboard", "Search car with sorting", nullptr));
        label_4->setText(QCoreApplication::translate("Dashboard", "Sell your car", nullptr));
        label->setText(QCoreApplication::translate("Dashboard", "M. Shariq Nadeem", nullptr));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H

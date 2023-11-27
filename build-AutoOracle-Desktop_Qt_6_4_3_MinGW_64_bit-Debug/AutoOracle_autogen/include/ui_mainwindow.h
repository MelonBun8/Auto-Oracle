/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1540, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/SAAD COMMUNICATION/Downloads/chrome_hqmSI9koUf (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(390, 150, 831, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Algerian")});
        font.setPointSize(35);
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);
        label->setFocusPolicy(Qt::StrongFocus);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::NoFrame);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(540, 240, 491, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Copperplate Gothic Bold")});
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setUnderline(false);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 340, 111, 91));
        QFont font2;
        font2.setKerning(true);
        label_3->setFont(font2);
        label_3->setMouseTracking(false);
        label_3->setFocusPolicy(Qt::TabFocus);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setPixmap(QPixmap(QString::fromUtf8("C:/Users/SAAD COMMUNICATION/Downloads/Untitled (1).png")));
        label_3->setScaledContents(true);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(620, 690, 221, 21));
        QFont font3;
        font3.setPointSize(11);
        font3.setItalic(true);
        pushButton->setFont(font3);
        pushButton->setFocusPolicy(Qt::ClickFocus);
        pushButton->setContextMenuPolicy(Qt::NoContextMenu);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(2, 5, 14);"));
        QIcon icon1;
        QString iconThemeName = QString::fromUtf8("applications-graphics");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton->setIcon(icon1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(-10, -20, 1560, 850));
        label_4->setFrameShadow(QFrame::Raised);
        label_4->setLineWidth(1);
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/MainUi Background.jpg")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(1240, 50, 81, 51));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/glow light png.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(890, 310, 631, 91));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/pngkit_clouds-png_16590.png")));
        label_6->setScaledContents(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(575, 516, 31, 21));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/glow light png.png")));
        label_7->setScaledContents(true);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(116, 206, 41, 31));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/glow light png.png")));
        label_8->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        label_5->raise();
        label_7->raise();
        label_8->raise();
        label_3->raise();
        label_4->raise();
        label->raise();
        label_2->raise();
        pushButton->raise();
        label_6->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Auto Oracle", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Welcome to Auto Oracle", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Accelerating your future", nullptr));
        label_3->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Press Here to Continue", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'newindow1.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWINDOW1_H
#define UI_NEWINDOW1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Newindow1
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_3;
    QLabel *name_label;
    QLineEdit *namelineEdit;
    QLabel *id_label;
    QLineEdit *idlineEdit;
    QLabel *password_label;
    QLineEdit *passlineEdit;
    QCheckBox *logincheck;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QCheckBox *checkBox;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;

    void setupUi(QMainWindow *Newindow1)
    {
        if (Newindow1->objectName().isEmpty())
            Newindow1->setObjectName("Newindow1");
        Newindow1->resize(1540, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/SAAD COMMUNICATION/Downloads/chrome_hqmSI9koUf (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        Newindow1->setWindowIcon(icon);
        centralwidget = new QWidget(Newindow1);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 590, 511, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Leelawadee UI")});
        font.setPointSize(12);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 30, 157);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -30, 1250, 661));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 65, 71);"));
        label->setScaledContents(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 100, 541, 501));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(4, 22, 72);"));
        name_label = new QLabel(centralwidget);
        name_label->setObjectName("name_label");
        name_label->setGeometry(QRect(80, 150, 111, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Palatino Linotype")});
        font1.setPointSize(11);
        font1.setBold(true);
        name_label->setFont(font1);
        name_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        namelineEdit = new QLineEdit(centralwidget);
        namelineEdit->setObjectName("namelineEdit");
        namelineEdit->setGeometry(QRect(80, 190, 381, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Palatino Linotype")});
        font2.setPointSize(10);
        font2.setBold(true);
        namelineEdit->setFont(font2);
        id_label = new QLabel(centralwidget);
        id_label->setObjectName("id_label");
        id_label->setGeometry(QRect(80, 270, 71, 20));
        id_label->setFont(font1);
        id_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        idlineEdit = new QLineEdit(centralwidget);
        idlineEdit->setObjectName("idlineEdit");
        idlineEdit->setGeometry(QRect(80, 310, 381, 31));
        idlineEdit->setFont(font2);
        password_label = new QLabel(centralwidget);
        password_label->setObjectName("password_label");
        password_label->setGeometry(QRect(80, 390, 111, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Palatino Linotype")});
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setItalic(false);
        password_label->setFont(font3);
        password_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        passlineEdit = new QLineEdit(centralwidget);
        passlineEdit->setObjectName("passlineEdit");
        passlineEdit->setGeometry(QRect(80, 430, 381, 31));
        passlineEdit->setFont(font3);
        passlineEdit->setClearButtonEnabled(false);
        logincheck = new QCheckBox(centralwidget);
        logincheck->setObjectName("logincheck");
        logincheck->setGeometry(QRect(80, 510, 291, 26));
        logincheck->setFont(font1);
        logincheck->setAutoFillBackground(false);
        logincheck->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(530, 760, 211, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Palatino Linotype")});
        font4.setPointSize(9);
        pushButton_2->setFont(font4);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(71, 71, 71);\n"
"border-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(550, 20, 71, 61));
        label_4->setPixmap(QPixmap(QString::fromUtf8("C:/Users/SAAD COMMUNICATION/Downloads/chrome_hqmSI9koUf (1).png")));
        label_4->setScaledContents(true);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(490, 430, 21, 31));
        checkBox->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/SAAD COMMUNICATION/Downloads/Lovepik_com-401039678-eye-icon-vector-element.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox->setIcon(icon1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(505, 420, 61, 51));
        label_7->setPixmap(QPixmap(QString::fromUtf8("C:/Users/SAAD COMMUNICATION/Downloads/Lovepik_com-401039678-eye-icon-vector-element.png")));
        label_7->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, -10, 1545, 810));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Login_ui-transformed.jpg")));
        label_2->setScaledContents(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(760, 100, 731, 491));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 24, 73);"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/pic1.jpg")));
        label_6->setScaledContents(true);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(180, 580, 291, 51));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 22, 68);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(780, 120, 361, 121));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Algerian")});
        font5.setPointSize(17);
        font5.setBold(true);
        label_5->setFont(font5);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(820, 310, 511, 71));
        label_9->setFont(font5);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1230, 480, 451, 71));
        label_10->setFont(font5);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(770, 480, 711, 71));
        label_11->setFont(font5);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Newindow1->setCentralWidget(centralwidget);
        label->raise();
        label_2->raise();
        label_3->raise();
        label_6->raise();
        pushButton_2->raise();
        label_8->raise();
        label_4->raise();
        name_label->raise();
        namelineEdit->raise();
        id_label->raise();
        idlineEdit->raise();
        password_label->raise();
        passlineEdit->raise();
        checkBox->raise();
        label_7->raise();
        logincheck->raise();
        pushButton->raise();
        label_5->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();

        retranslateUi(Newindow1);

        QMetaObject::connectSlotsByName(Newindow1);
    } // setupUi

    void retranslateUi(QMainWindow *Newindow1)
    {
        Newindow1->setWindowTitle(QCoreApplication::translate("Newindow1", "USER LOGIN", nullptr));
        pushButton->setText(QCoreApplication::translate("Newindow1", "LOG IN", nullptr));
        label->setText(QString());
        label_3->setText(QString());
        name_label->setText(QCoreApplication::translate("Newindow1", "USERNAME", nullptr));
        namelineEdit->setText(QString());
        namelineEdit->setPlaceholderText(QCoreApplication::translate("Newindow1", "Enter your name", nullptr));
        id_label->setText(QCoreApplication::translate("Newindow1", "USERID", nullptr));
        idlineEdit->setPlaceholderText(QCoreApplication::translate("Newindow1", "Enter your Log In ID", nullptr));
        password_label->setText(QCoreApplication::translate("Newindow1", "PASSWORD", nullptr));
        passlineEdit->setPlaceholderText(QCoreApplication::translate("Newindow1", "Enter your password", nullptr));
        logincheck->setText(QCoreApplication::translate("Newindow1", "Log in For First Time?", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Newindow1", "For Admin Log In Click Here", nullptr));
        label_4->setText(QString());
        checkBox->setText(QString());
        label_7->setText(QString());
        label_2->setText(QString());
        label_6->setText(QString());
        label_8->setText(QString());
        label_5->setText(QCoreApplication::translate("Newindow1", "BUY your dream car", nullptr));
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Newindow1: public Ui_Newindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWINDOW1_H

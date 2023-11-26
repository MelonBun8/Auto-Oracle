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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Newindow1
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *namelineEdit;
    QLineEdit *idlineEdit;
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
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *tab_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QLabel *name_label;
    QLabel *id_label;
    QLabel *password_label;

    void setupUi(QMainWindow *Newindow1)
    {
        if (Newindow1->objectName().isEmpty())
            Newindow1->setObjectName("Newindow1");
        Newindow1->resize(1540, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/chrome_hqmSI9koUf (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        Newindow1->setWindowIcon(icon);
        centralwidget = new QWidget(Newindow1);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -30, 1250, 661));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 65, 71);"));
        label->setScaledContents(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 100, 541, 501));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(4, 22, 72);"));
        namelineEdit = new QLineEdit(centralwidget);
        namelineEdit->setObjectName("namelineEdit");
        namelineEdit->setGeometry(QRect(20, 190, 381, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Palatino Linotype")});
        font.setPointSize(10);
        font.setBold(true);
        namelineEdit->setFont(font);
        idlineEdit = new QLineEdit(centralwidget);
        idlineEdit->setObjectName("idlineEdit");
        idlineEdit->setGeometry(QRect(20, 310, 381, 31));
        idlineEdit->setFont(font);
        passlineEdit = new QLineEdit(centralwidget);
        passlineEdit->setObjectName("passlineEdit");
        passlineEdit->setGeometry(QRect(30, 420, 381, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Palatino Linotype")});
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(false);
        passlineEdit->setFont(font1);
        passlineEdit->setClearButtonEnabled(false);
        logincheck = new QCheckBox(centralwidget);
        logincheck->setObjectName("logincheck");
        logincheck->setGeometry(QRect(30, 490, 291, 26));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Palatino Linotype")});
        font2.setPointSize(11);
        font2.setBold(true);
        logincheck->setFont(font2);
        logincheck->setAutoFillBackground(false);
        logincheck->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(530, 760, 211, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Palatino Linotype")});
        font3.setPointSize(9);
        pushButton_2->setFont(font3);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(71, 71, 71);\n"
"border-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1130, 10, 71, 61));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/chrome_hqmSI9koUf (1).png")));
        label_4->setScaledContents(true);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(450, 420, 21, 31));
        checkBox->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../Downloads/Lovepik_com-401039678-eye-icon-vector-element.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox->setIcon(icon1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(450, 410, 61, 51));
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/Lovepik_com-401039678-eye-icon-vector-element.png")));
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
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Algerian")});
        font4.setPointSize(17);
        font4.setBold(true);
        label_5->setFont(font4);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(820, 310, 511, 71));
        label_9->setFont(font4);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1230, 480, 451, 71));
        label_10->setFont(font4);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(770, 480, 711, 71));
        label_11->setFont(font4);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 140, 501, 391));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 28, 83);\n"
"background-color: rgb(250, 250, 250);\n"
"background-color: rgb(253, 253, 253);\n"
"background-color: rgb(252, 252, 252);\n"
"color: rgb(2, 60, 186);\n"
"background-color: rgb(6, 69, 207);\n"
"background-color: rgb(1, 15, 45);"));
        tab = new QWidget();
        tab->setObjectName("tab");
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(80, 230, 161, 31));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(20, 70, 271, 31));
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(20, 160, 271, 31));
        label_12 = new QLabel(tab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 35, 111, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Palatino Linotype")});
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setItalic(false);
        label_12->setFont(font5);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"Palatino Linotype\";"));
        label_13 = new QLabel(tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 125, 91, 21));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 10pt \"Palatino Linotype\";"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 40, 271, 31));
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(20, 110, 271, 31));
        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(20, 180, 271, 31));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(110, 280, 121, 29));
        comboBox = new QComboBox(tab_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 230, 101, 28));
        name_label = new QLabel(tab_2);
        name_label->setObjectName("name_label");
        name_label->setGeometry(QRect(20, 10, 111, 20));
        name_label->setFont(font2);
        name_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        id_label = new QLabel(tab_2);
        id_label->setObjectName("id_label");
        id_label->setGeometry(QRect(20, 80, 71, 20));
        id_label->setFont(font2);
        id_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        password_label = new QLabel(tab_2);
        password_label->setObjectName("password_label");
        password_label->setGeometry(QRect(20, 150, 111, 21));
        password_label->setFont(font1);
        password_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_2, QString());
        Newindow1->setCentralWidget(centralwidget);
        label->raise();
        label_2->raise();
        label_3->raise();
        label_6->raise();
        pushButton_2->raise();
        label_8->raise();
        label_4->raise();
        namelineEdit->raise();
        idlineEdit->raise();
        passlineEdit->raise();
        checkBox->raise();
        label_7->raise();
        logincheck->raise();
        label_5->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        tabWidget->raise();

        retranslateUi(Newindow1);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Newindow1);
    } // setupUi

    void retranslateUi(QMainWindow *Newindow1)
    {
        Newindow1->setWindowTitle(QCoreApplication::translate("Newindow1", "USER LOGIN", nullptr));
        label->setText(QString());
        label_3->setText(QString());
        namelineEdit->setText(QString());
        namelineEdit->setPlaceholderText(QCoreApplication::translate("Newindow1", "Enter your name", nullptr));
        idlineEdit->setPlaceholderText(QCoreApplication::translate("Newindow1", "Enter your Log In ID", nullptr));
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
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_4->setText(QCoreApplication::translate("Newindow1", "Log In", nullptr));
        label_12->setText(QCoreApplication::translate("Newindow1", "USER NAME :", nullptr));
        label_13->setText(QCoreApplication::translate("Newindow1", "PASSWORD :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Newindow1", "Log In", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Newindow1", "Sign Up Now", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Newindow1", "Below 18", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Newindow1", "18", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Newindow1", "19", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Newindow1", "20", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Newindow1", "21", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("Newindow1", "22", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("Newindow1", "23", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("Newindow1", "24", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("Newindow1", "25", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("Newindow1", "26", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("Newindow1", "27", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("Newindow1", "28", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("Newindow1", "29", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("Newindow1", "30", nullptr));

        name_label->setText(QCoreApplication::translate("Newindow1", "USERNAME", nullptr));
        id_label->setText(QCoreApplication::translate("Newindow1", "USERID", nullptr));
        password_label->setText(QCoreApplication::translate("Newindow1", "PASSWORD", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Newindow1", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Newindow1: public Ui_Newindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWINDOW1_H

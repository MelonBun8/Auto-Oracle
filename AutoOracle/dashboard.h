#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QtWidgets>
#include <QPropertyAnimation>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <iostream>
#include <iomanip>
#include <QMessageBox>
#include <QtGlobal>


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
    void updateProfile();
    void purchaseData();
    void soldData();
    void hideSells();
    void hidePurchase();
    void putSell();
    void putPurchase();

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::Dashboard *ui;
    QPropertyAnimation *leftWidgetAnimation;
    QPropertyAnimation *rightWidgetAnimation;
    QPropertyAnimation *stackWidgetAnimation;

protected:
    void closeEvent(QCloseEvent *event) override;

};

#endif // DASHBOARD_H

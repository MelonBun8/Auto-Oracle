#include "dashboard.h"
#include "newindow1.h"
#include "./ui_dashboard.h"
#include <QPropertyAnimation>
#include <QPainter>
#include <QPushButton>
#include <QPalette>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

User current_user;
Stack_sell s1;
Stack_purchase p1;
Car current_car;
int Max_sell=-1;
int Max_purchase= -1;
int sell_toggle=0;
int purchase_toggle=0;
int sell_move=0;
int sell_back=0;
int purchase_move=0;
int purchase_back=0;
int sale_toggle=0;
int sale_move=0;
int totalCarsOnSale=0;
LinkedList2 carList;
LinkedList L1;
Car_Queue q1;

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->pushButton_3->setStyleSheet("background-color: #9141d9; border: none; color: #ffffff;");
    ui->pushButton_5->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
    ui->pushButton_4->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
    ui->pushButton_6->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
    ui->pushButton_7->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
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
        ui->pushButton_6->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_7->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->stackedWidget->setCurrentIndex(0);
    });

    QObject::connect(ui->pushButton_4, &QPushButton::clicked, [&]() {
        ui->pushButton_4->setStyleSheet("background-color: #9141d9; border: none; color: #ffffff;");
        ui->pushButton_3->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_5->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_6->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_7->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->stackedWidget->setCurrentIndex(1);
    });

    if(current_user.status=="false")
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }
    else
    {
        ui->pushButton_5->setText("Sell Your Car");
        ui->stackedWidget_4->setCurrentIndex(1);
    }

    //purple #9141d9 blue #263173 white #ffffff
    QObject::connect(ui->pushButton_5, &QPushButton::clicked, [&]() {
        ui->pushButton_5->setStyleSheet("background-color: #9141d9; border: none; color: #ffffff;");
        ui->pushButton_3->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_4->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_6->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_7->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->stackedWidget->setCurrentIndex(4);
        if(current_user.status=="false")
        {
            ui->stackedWidget_4->setCurrentIndex(0);
        }
        else
        {

            ui->stackedWidget_4->setCurrentIndex(1);
        }
    });

    QObject::connect(ui->pushButton_6, &QPushButton::clicked, [&]() {
        ui->pushButton_6->setStyleSheet("background-color: #9141d9; border: none; color: #ffffff;");
        ui->pushButton_3->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_4->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_5->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_7->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->stackedWidget->setCurrentIndex(3);
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(0);

    });

    QObject::connect(ui->pushButton_7, &QPushButton::clicked, [&]() {
        ui->pushButton_7->setStyleSheet("background-color: #9141d9; border: none; color: #ffffff;");
        ui->pushButton_3->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_4->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_6->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_5->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->stackedWidget->setCurrentIndex(2);
    });


    connect(ui->pushButton, &QPushButton::clicked, this, &Dashboard::expandLeftWithAnimation);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Dashboard::expandRightWithAnimation);


    QFile file("Currentuserdetails.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    }

    // Create a QTextStream to read data from the file
    QTextStream inz(&file);

    // Read the content of the file into a QString
    QString userDetails = inz.readLine();

    QFile fp("Userdetails.txt");
    if (!fp.open(QIODevice::ReadOnly | QIODevice::Text)) {

    }

    QTextStream in(&fp);
    int numberOfObjects = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        ++numberOfObjects;
    }

    fp.close();

    User* userArray = new User[numberOfObjects];

        // Read the file again to populate your dynamically allocated object array
    QFile fp1("Userdetails.txt");
    if (!fp1.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Handle error opening file
        delete[] userArray; // Clean up allocated memory

    }
    QTextStream iny(&fp1);
    int currentIndex = 0;
    User temp2;
    while (!iny.atEnd()) {
        QString line1 = iny.readLine();
        User* newUser = temp2.createFromString(line1);
        userArray[currentIndex] = *newUser; // Assuming User is copyable
        ++currentIndex;
    }

    fp1.close();
    for(int i=0; i<numberOfObjects; ++i)
    {
        L1.addNode(userArray[i]);
    }


    QFile fp3("Cardetails.txt");
    if (!fp3.open(QIODevice::ReadOnly | QIODevice::Text)) {
    }

    QTextStream init(&fp3);
    int numberOfCarObjects = 0;

    while (!init.atEnd()) {
        QString line1 = init.readLine();
        ++numberOfCarObjects;
    }

    fp3.close();

    Car* carArray = new Car[numberOfCarObjects];

        // Read the file again to populate your dynamically allocated object array
    QFile fp4("Cardetails.txt");
    if (!fp4.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Handle error opening file
        delete[] carArray; // Clean up allocated memory
        //return 1;
    }
    QTextStream init2(&fp4);
    int currentIndex1 = 0;
    Car temp3;
    while (!init2.atEnd()) {
        QString line1 = init2.readLine();
        Car* newCar = temp3.carcreateFromString(line1);
        carArray[currentIndex1] = *newCar; // Assuming User is copyable
        ++currentIndex1;
    }

    fp4.close();
    for(int i=0; i<numberOfCarObjects; ++i)
    {
        carList.addNode(carArray[i]);
    }

    current_user= L1.currentid_search(userDetails);
    s1= Stack_sell(current_user);
    p1= Stack_purchase(current_user);
    q1.add_cars(carList.head);
    totalCarsOnSale= q1.getCount();
    toggle();
    emptySales();
    fillSales();
    Max_sell= s1.getRestore1();
    Max_purchase= p1.getRestore2();
    hideSells();
    hidePurchase();
    soldData();
    purchaseData();
    putSell();
    putPurchase();


    ui->label->setText(current_user.username);
    ui->textEdit->setText(current_user.description);
    ui->label_19->setText(current_user.age);
    ui->label_9->setText(current_user.username);
    ui->label_12->setText(current_user.id);
    ui->label_14->setText(current_user.password);
    ui->label_21->setText(current_user.age);
    ui->textEdit_2->setText(current_user.description);
    ui->label_130->setText(current_user.email);
    ui->label_131->setText(current_user.phone);
    ui->label_16->setPixmap(QPixmap(current_user.profile_pic));
    ui->label_22->setPixmap(QPixmap(current_user.profile_pic));

}

void Dashboard::fillSales()
{
    int j=(totalCarsOnSale-1)*17;
    
    for (int i = totalCarsOnSale-1; i >= 0; --i) {
        QString id= q1.dequeue();
        Car temp= carList.currentid_search2(id);
            QString Brand = QString("label_%1").arg(j + 192);
            QString Model = QString("label_%1").arg(j + 205);
            QString Price = QString("label_%1").arg(j + 194);
            QString MFG = QString("label_%1").arg(j + 196);
            QString Cylinders = QString("label_%1").arg(j + 201);
            QString Fuel = QString("label_%1").arg(j + 202);
            QString Color = QString("label_%1").arg(j + 203);
            QString Pic = QString("label_%1").arg(j + 197);
            QString ID = QString("label_%1").arg(j + 207);
            QString Description = QString("textEdit_%1").arg(i + 3);
            QString widgetName = QString("widget_%1").arg(i + 3);
            QLabel *label1 = ui->stackedWidget_6->findChild<QLabel *>(Brand);
            QLabel *label2 = ui->stackedWidget_6->findChild<QLabel *>(Model);
            QLabel *label3 = ui->stackedWidget_6->findChild<QLabel *>(Price);
            QLabel *label4 = ui->stackedWidget_6->findChild<QLabel *>(MFG);
            QLabel *label5 = ui->stackedWidget_6->findChild<QLabel *>(Cylinders);
            QLabel *label6 = ui->stackedWidget_6->findChild<QLabel *>(Fuel);
            QLabel *label7 = ui->stackedWidget_6->findChild<QLabel *>(Color);
            QLabel *label8 = ui->stackedWidget_6->findChild<QLabel *>(Pic);
            QLabel *label9 = ui->stackedWidget_6->findChild<QLabel *>(ID);

            QTextEdit *textEdit = ui->stackedWidget_6->findChild<QTextEdit *>(Description);
            QWidget *childWidget = ui->stackedWidget_6->findChild<QWidget *>(widgetName);
            label1->setText(temp.manufacture);
            label2->setText(temp.model);
            label3->setText(temp.price);
            label4->setText(temp.year);
            label5->setText(temp.cylinders);
            label6->setText(temp.fuel);
            QColor color(temp.paint_color); // Convert color name to QColor
            label7->setStyleSheet(QString("background-color: %1;").arg(color.name()));
            label8->setPixmap(QPixmap(temp.pic));
            label9->setText(temp.id);
            textEdit->setPlainText(temp.discription);
            childWidget->show();


            j= j-17;
        }
}

void Dashboard::emptySales()
{
    if(totalCarsOnSale<24)
    {
         ui->widget_26->hide();
    }
    if(totalCarsOnSale<23)
    {
         ui->widget_25->hide();
    }
    if(totalCarsOnSale<22)
    {
         ui->widget_24->hide();
    }
    if(totalCarsOnSale<21)
    {
         ui->widget_23->hide();
    }
    if(totalCarsOnSale<20)
    {
         ui->widget_22->hide();
    }
    if(totalCarsOnSale<19)
    {
         ui->widget_21->hide();
    }
    if(totalCarsOnSale<18)
    {
         ui->widget_20->hide();
    }
    if(totalCarsOnSale<17)
    {
         ui->widget_19->hide();
    }
    if(totalCarsOnSale<16)
    {
         ui->widget_18->hide();
    }
    if(totalCarsOnSale<15)
    {
         ui->widget_17->hide();
    }
    if(totalCarsOnSale<14)
    {
         ui->widget_16->hide();
    }
    if(totalCarsOnSale<13)
    {
         ui->widget_15->hide();
    }
    if(totalCarsOnSale<12)
    {
         ui->widget_14->hide();
    }
    if(totalCarsOnSale<11)
    {
         ui->widget_13->hide();
    }
    if(totalCarsOnSale<10)
    {
         ui->widget_12->hide();
    }
    if(totalCarsOnSale<9)
    {
         ui->widget_11->hide();
    }
    if(totalCarsOnSale<8)
    {
         ui->widget_10->hide();
    }
    if(totalCarsOnSale<7)
    {
         ui->widget_9->hide();
    }
    if(totalCarsOnSale<6)
    {
         ui->widget_8->hide();
    }
    if(totalCarsOnSale<5)
    {
         ui->widget_7->hide();
    }
    if(totalCarsOnSale<4)
    {
         ui->widget_6->hide();
    }
    if(totalCarsOnSale<3)
    {
         ui->widget_5->hide();
    }
    if(totalCarsOnSale<2)
    {
         ui->widget_4->hide();
    }
    if(totalCarsOnSale<1)
    {
         ui->widget_3->hide();
    }
}

void Dashboard::toggle()
{
    if(totalCarsOnSale<=6)
    {
        sale_toggle=0;
    }
    else if(totalCarsOnSale<=12)
    {
        sale_toggle=1;
    }
    else if(totalCarsOnSale<=18)
    {
        sale_toggle=2;
    }
    else if(totalCarsOnSale<=24)
    {
        sale_toggle=3;
    }
}

void Dashboard::on_pushButton_73_clicked()
{
    if(sale_toggle==0)
    {
        return;
    }
    else if(sale_toggle==1 && sale_move==0)
    {
        sale_move++;
        ui->stackedWidget_6->setCurrentIndex(1);
    }
    else if(sale_toggle==2 && sale_move==1)
    {
        sale_move++;
        ui->stackedWidget_6->setCurrentIndex(2);
    }
    else if(sale_toggle==3 && sale_move==2)
    {
        sale_move++;
        ui->stackedWidget_6->setCurrentIndex(3);
    }
    else
    {
        return;
    }
}


void Dashboard::on_pushButton_74_clicked()
{
    if(sale_toggle==0)
    {
        return;
    }
    else if(sale_toggle==1 && sale_move==1)
    {
        sale_move--;
        ui->stackedWidget_6->setCurrentIndex(0);
    }
    else if(sale_toggle==2 && sale_move==2)
    {
        sale_move--;
        ui->stackedWidget_6->setCurrentIndex(1);
    }
    else if(sale_toggle==3 && sale_move==3)
    {
        sale_move--;
        ui->stackedWidget_6->setCurrentIndex(2);
    }
    else
    {
        return;
    }
}

void Dashboard::hideSells()
{
    ui->label_26->raise();
    ui->label_28->raise();
    ui->label_30->raise();
    ui->label_32->raise();
    ui->label_34->raise();
    ui->label_36->raise();
    ui->label_38->raise();
    ui->label_40->raise();
    ui->label_42->raise();
    ui->label_44->raise();
    ui->label_46->raise();
    ui->label_48->raise();
    ui->label_50->raise();
    ui->label_52->raise();
    ui->label_54->raise();
    ui->label_56->raise();
    ui->label_58->raise();
    ui->label_60->raise();
    ui->label_62->raise();
    ui->label_64->raise();
    ui->label_66->raise();
    ui->label_68->raise();
    ui->label_70->raise();
    ui->label_72->raise();
    ui->label_74->raise();

}

void Dashboard::hidePurchase()
{
    ui->label_76->raise();
    ui->label_78->raise();
    ui->label_80->raise();
    ui->label_82->raise();
    ui->label_84->raise();
    ui->label_86->raise();
    ui->label_88->raise();
    ui->label_90->raise();
    ui->label_92->raise();
    ui->label_94->raise();
    ui->label_96->raise();
    ui->label_98->raise();
    ui->label_100->raise();
    ui->label_102->raise();
    ui->label_104->raise();
    ui->label_106->raise();
    ui->label_108->raise();
    ui->label_110->raise();
    ui->label_112->raise();
    ui->label_114->raise();
    ui->label_116->raise();
    ui->label_118->raise();
    ui->label_120->raise();
    ui->label_122->raise();
    ui->label_124->raise();

}

void Dashboard::putSell()
{
    Car obj;
    QString id;
    soldData();
    if(Max_sell==-1)
    {
        return;
    }
    if(Max_sell>=0)
    {
        id= s1.pop();
        obj = carList.currentid_search2(id);
        ui->label_146->raise();
        ui->label_23->raise();
        ui->label_140->raise();
        ui->label_147->raise();
        ui->label_145->raise();
        ui->label_144->raise();
        ui->label_143->raise();
        ui->label_146->setPixmap(QPixmap(obj.pic));
        ui->label_23->setText(obj.manufacture);
        ui->label_140->setText(obj.model);
        ui->label_147->setText(obj.price);
        ui->label_145->setText(obj.status);
    }
    if(Max_sell>=1)
    {
        id= s1.pop();
        obj = carList.currentid_search2(id);
        ui->label_148->raise();
        ui->label_149->raise();
        ui->label_150->raise();
        ui->label_151->raise();
        ui->label_152->raise();
        ui->label_153->raise();
        ui->label_154->raise();
        ui->label_148->setPixmap(QPixmap(obj.pic));
        ui->label_149->setText(obj.manufacture);
        ui->label_150->setText(obj.model);
        ui->label_153->setText(obj.price);
        ui->label_154->setText(obj.status);
    }
    if(Max_sell>=2)
    {
        id= s1.pop();
        obj = carList.currentid_search2(id);
        ui->label_155->raise();
        ui->label_156->raise();
        ui->label_157->raise();
        ui->label_158->raise();
        ui->label_159->raise();
        ui->label_160->raise();
        ui->label_161->raise();
        ui->label_155->setPixmap(QPixmap(obj.pic));
        ui->label_156->setText(obj.manufacture);
        ui->label_157->setText(obj.model);
        ui->label_160->setText(obj.price);
        ui->label_161->setText(obj.status);
    }
    if(Max_sell>=3)
    {
        id= s1.pop();
        obj = carList.currentid_search2(id);
        ui->label_162->raise();
        ui->label_163->raise();
        ui->label_164->raise();
        ui->label_165->raise();
        ui->label_166->raise();
        ui->label_167->raise();
        ui->label_168->raise();
        ui->label_162->setPixmap(QPixmap(obj.pic));
        ui->label_163->setText(obj.manufacture);
        ui->label_164->setText(obj.model);
        ui->label_167->setText(obj.price);
        ui->label_168->setText(obj.status);
    }
    if(Max_sell>=4)
    {
        id= s1.pop();
        obj = carList.currentid_search2(id);
        ui->label_169->raise();
        ui->label_170->raise();
        ui->label_171->raise();
        ui->label_172->raise();
        ui->label_173->raise();
        ui->label_174->raise();
        ui->label_175->raise();
        ui->label_169->setPixmap(QPixmap(obj.pic));
        ui->label_170->setText(obj.manufacture);
        ui->label_171->setText(obj.model);
        ui->label_174->setText(obj.price);
        ui->label_175->setText(obj.status);
    }
    if(Max_sell>=5)
    {
        ui->label_35->setText(s1.pop());
    }
    if(Max_sell>=6)
    {
        ui->label_37->setText(s1.pop());
    }
    if(Max_sell>=7)
    {
        ui->label_39->setText(s1.pop());
    }
    if(Max_sell>=8)
    {
        ui->label_41->setText(s1.pop());
    }
    if(Max_sell>=9)
    {
        ui->label_43->setText(s1.pop());
    }
    if(Max_sell>=10)
    {
        ui->label_45->setText(s1.pop());
    }
    if(Max_sell>=11)
    {
        ui->label_47->setText(s1.pop());
    }
    if(Max_sell>=12)
    {
        ui->label_49->setText(s1.pop());
    }
    if(Max_sell>=13)
    {
        ui->label_51->setText(s1.pop());
    }
    if(Max_sell>=14)
    {
        ui->label_53->setText(s1.pop());
    }
    if(Max_sell>=15)
    {
        ui->label_55->setText(s1.pop());
    }
    if(Max_sell>=16)
    {
        ui->label_57->setText(s1.pop());
    }
    if(Max_sell>=17)
    {
        ui->label_59->setText(s1.pop());
    }
    if(Max_sell>=18)
    {
        ui->label_61->setText(s1.pop());
    }
    if(Max_sell>=19)
    {
        ui->label_63->setText(s1.pop());
    }
    if(Max_sell>=20)
    {
        ui->label_65->setText(s1.pop());
    }
    if(Max_sell>=21)
    {
        ui->label_67->setText(s1.pop());
    }
    if(Max_sell>=22)
    {
        ui->label_69->setText(s1.pop());
    }
    if(Max_sell>=23)
    {
        ui->label_71->setText(s1.pop());
    }
    if(Max_sell>=24)
    {
        ui->label_73->setText(s1.pop());
    }

    s1.rest();
}

void Dashboard::putPurchase()
{
    Car obj;
    QString id;
    purchaseData();
    if(Max_purchase==-1)
    {
        return;
    }
    if(Max_purchase>=0)
    {
        id= p1.pop();
        obj = carList.currentid_search2(id);
        ui->label_633->raise();
        ui->label_630->raise();
        ui->label_612->raise();
        ui->label_620->raise();
        ui->label_618->raise();
        ui->label_609->raise();
        ui->label_624->raise();
        ui->label_633->setPixmap(QPixmap(obj.pic));
        ui->label_630->setText(obj.manufacture);
        ui->label_612->setText(obj.model);
        ui->label_620->setText(obj.price);
        ui->label_618->setText(obj.status);
    }
    if(Max_purchase>=1)
    {
        id= p1.pop();
        obj = carList.currentid_search2(id);
        ui->label_631->raise();
        ui->label_610->raise();
        ui->label_614->raise();
        ui->label_628->raise();
        ui->label_615->raise();
        ui->label_625->raise();
        ui->label_606->raise();
        ui->label_631->setPixmap(QPixmap(obj.pic));
        ui->label_610->setText(obj.manufacture);
        ui->label_614->setText(obj.model);
        ui->label_628->setText(obj.price);
        ui->label_615->setText(obj.status);
    }
    if(Max_purchase>=2)
    {
        id= p1.pop();
        obj = carList.currentid_search2(id);
        ui->label_611->raise();
        ui->label_632->raise();
        ui->label_621->raise();
        ui->label_622->raise();
        ui->label_601->raise();
        ui->label_613->raise();
        ui->label_600->raise();
        ui->label_611->setPixmap(QPixmap(obj.pic));
        ui->label_632->setText(obj.manufacture);
        ui->label_621->setText(obj.model);
        ui->label_622->setText(obj.price);
        ui->label_601->setText(obj.status);
    }
    if(Max_purchase>=3)
    {
        id= p1.pop();
        obj = carList.currentid_search2(id);
        ui->label_629->raise();
        ui->label_616->raise();
        ui->label_623->raise();
        ui->label_608->raise();
        ui->label_599->raise();
        ui->label_603->raise();
        ui->label_626->raise();
        ui->label_629->setPixmap(QPixmap(obj.pic));
        ui->label_616->setText(obj.manufacture);
        ui->label_623->setText(obj.model);
        ui->label_608->setText(obj.price);
        ui->label_599->setText(obj.status);
    }
    if(Max_purchase>=4)
    {
        id= p1.pop();
        obj = carList.currentid_search2(id);
        ui->label_604->raise();
        ui->label_619->raise();
        ui->label_627->raise();
        ui->label_602->raise();
        ui->label_607->raise();
        ui->label_617->raise();
        ui->label_605->raise();
        ui->label_604->setPixmap(QPixmap(obj.pic));
        ui->label_619->setText(obj.manufacture);
        ui->label_627->setText(obj.model);
        ui->label_602->setText(obj.price);
        ui->label_607->setText(obj.status);
    }
    if(Max_purchase>=5)
    {
        ui->label_85->setText(p1.pop());
    }
    if(Max_purchase>=6)
    {
        ui->label_87->setText(p1.pop());
    }
    if(Max_purchase>=7)
    {
        ui->label_89->setText(p1.pop());
    }
    if(Max_purchase>=8)
    {
        ui->label_91->setText(p1.pop());
    }
    if(Max_purchase>=9)
    {
        ui->label_93->setText(p1.pop());
    }
    if(Max_purchase>=10)
    {
        ui->label_95->setText(p1.pop());
    }
    if(Max_purchase>=11)
    {
        ui->label_97->setText(p1.pop());
    }
    if(Max_purchase>=12)
    {
        ui->label_99->setText(p1.pop());
    }
    if(Max_purchase>=13)
    {
        ui->label_101->setText(p1.pop());
    }
    if(Max_purchase>=14)
    {
        ui->label_103->setText(p1.pop());
    }
    if(Max_purchase>=15)
    {
        ui->label_105->setText(p1.pop());
    }
    if(Max_purchase>=16)
    {
        ui->label_107->setText(p1.pop());
    }
    if(Max_purchase>=17)
    {
        ui->label_109->setText(p1.pop());
    }
    if(Max_purchase>=18)
    {
        ui->label_111->setText(p1.pop());
    }
    if(Max_purchase>=19)
    {
        ui->label_113->setText(p1.pop());
    }
    if(Max_purchase>=20)
    {
        ui->label_115->setText(p1.pop());
    }
    if(Max_purchase>=21)
    {
        ui->label_117->setText(p1.pop());
    }
    if(Max_purchase>=22)
    {
        ui->label_119->setText(p1.pop());
    }
    if(Max_purchase>=23)
    {
        ui->label_121->setText(p1.pop());
    }
    if(Max_purchase>=24)
    {
        ui->label_123->setText(p1.pop());
    }

    p1.rest();
}

void Dashboard::purchaseData()
{
    if(Max_purchase<5)
    {
        if(Max_purchase==0)
        {
            ui->label_76->lower();
        }
        else if(Max_purchase==1)
        {
            ui->label_76->lower();
            ui->label_78->lower();
        }
        else if(Max_purchase==2)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
        }
        else if(Max_purchase==3)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
        }
        else if(Max_purchase==1)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
        }

        purchase_toggle=0;

    }
    else if(Max_purchase>=5 && Max_purchase<10)
    {
        if(Max_purchase==5)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
        }
        else if(Max_purchase==6)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
        }
        else if(Max_purchase==7)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
        }
        else if(Max_purchase==8)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
        }
        else if(Max_purchase==9)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
        }
        purchase_toggle=1;
    }
    else if(Max_purchase>=10 && Max_purchase<15)
    {
        if(Max_purchase==10)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
        }
        else if(Max_purchase==11)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
        }
        else if(Max_purchase==12)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
        }
        else if(Max_purchase==13)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
        }
        else if(Max_purchase==14)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
        }
        purchase_toggle=2;
    }
    else if(Max_purchase>=15 && Max_purchase<20)
    {
        if(Max_purchase==15)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
            ui->label_106->lower();
        }
        else if(Max_purchase==16)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
            ui->label_106->lower();
            ui->label_108->lower();
        }
        else if(Max_purchase==17)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
            ui->label_106->lower();
            ui->label_108->lower();
            ui->label_110->lower();
        }
        else if(Max_purchase==18)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
            ui->label_106->lower();
            ui->label_108->lower();
            ui->label_110->lower();
            ui->label_112->lower();
        }
        else if(Max_purchase==19)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
            ui->label_106->lower();
            ui->label_108->lower();
            ui->label_110->lower();
            ui->label_112->lower();
            ui->label_114->lower();
        }
        purchase_toggle=3;
    }
    else if(Max_purchase>=20 && Max_purchase<25)
    {
        if(Max_purchase==20)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
            ui->label_106->lower();
            ui->label_108->lower();
            ui->label_110->lower();
            ui->label_112->lower();
            ui->label_114->lower();
            ui->label_116->lower();
        }
        else if(Max_purchase==21)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
            ui->label_106->lower();
            ui->label_108->lower();
            ui->label_110->lower();
            ui->label_112->lower();
            ui->label_114->lower();
            ui->label_116->lower();
            ui->label_118->lower();
        }
        else if(Max_purchase==22)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
            ui->label_106->lower();
            ui->label_108->lower();
            ui->label_110->lower();
            ui->label_112->lower();
            ui->label_114->lower();
            ui->label_116->lower();
            ui->label_118->lower();
            ui->label_120->lower();
        }
        else if(Max_purchase==23)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
            ui->label_106->lower();
            ui->label_108->lower();
            ui->label_110->lower();
            ui->label_112->lower();
            ui->label_114->lower();
            ui->label_116->lower();
            ui->label_118->lower();
            ui->label_120->lower();
            ui->label_122->lower();
        }
        else if(Max_purchase==24)
        {
            ui->label_76->lower();
            ui->label_78->lower();
            ui->label_80->lower();
            ui->label_82->lower();
            ui->label_84->lower();
            ui->label_86->lower();
            ui->label_88->lower();
            ui->label_90->lower();
            ui->label_92->lower();
            ui->label_94->lower();
            ui->label_96->lower();
            ui->label_98->lower();
            ui->label_100->lower();
            ui->label_102->lower();
            ui->label_104->lower();
            ui->label_106->lower();
            ui->label_108->lower();
            ui->label_110->lower();
            ui->label_112->lower();
            ui->label_114->lower();
            ui->label_116->lower();
            ui->label_118->lower();
            ui->label_120->lower();
            ui->label_122->lower();
            ui->label_124->lower();
        }
        purchase_toggle=4;
    }
}

void Dashboard::soldData()
{
    if(Max_sell<5)
    {
        if(Max_sell==0)
        {
            ui->label_26->lower();
        }
        else if(Max_sell==1)
        {
            ui->label_26->lower();
            ui->label_28->lower();
        }
        else if(Max_sell==2)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
        }
        else if(Max_sell==3)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
        }
        else if(Max_sell==1)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
        }
        sell_toggle=0;
    }
    else if(Max_sell>5 && Max_sell<10)
    {
        if(Max_sell==5)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
        }
        else if(Max_sell==6)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
        }
        else if(Max_sell==7)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
        }
        else if(Max_sell==8)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
        }
        else if(Max_sell==9)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
        }
        sell_toggle=1;
    }
    else if(Max_sell>10 && Max_sell<15)
    {
        if(Max_sell==10)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
        }
        else if(Max_sell==11)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
        }
        else if(Max_sell==12)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
        }
        else if(Max_purchase==13)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
        }
        else if(Max_sell==14)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
        }
        sell_toggle=2;
    }
    else if(Max_sell>15 && Max_sell<20)
    {
        if(Max_sell==15)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
            ui->label_56->lower();
        }
        else if(Max_sell==16)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
            ui->label_56->lower();
            ui->label_58->lower();
        }
        else if(Max_sell==17)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
            ui->label_56->lower();
            ui->label_58->lower();
            ui->label_60->lower();
        }
        else if(Max_sell==18)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
            ui->label_56->lower();
            ui->label_58->lower();
            ui->label_60->lower();
            ui->label_62->lower();
        }
        else if(Max_sell==19)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
            ui->label_56->lower();
            ui->label_58->lower();
            ui->label_60->lower();
            ui->label_62->lower();
            ui->label_64->lower();
        }
        sell_toggle=3;
    }
    else if(Max_sell>20 && Max_sell<25)
    {
        if(Max_sell==20)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
            ui->label_56->lower();
            ui->label_58->lower();
            ui->label_60->lower();
            ui->label_62->lower();
            ui->label_64->lower();
            ui->label_66->lower();
        }
        else if(Max_sell==21)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
            ui->label_56->lower();
            ui->label_58->lower();
            ui->label_60->lower();
            ui->label_62->lower();
            ui->label_64->lower();
            ui->label_66->lower();
            ui->label_68->lower();
        }
        else if(Max_sell==22)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
            ui->label_56->lower();
            ui->label_58->lower();
            ui->label_60->lower();
            ui->label_62->lower();
            ui->label_64->lower();
            ui->label_66->lower();
            ui->label_68->lower();
            ui->label_70->lower();
        }
        else if(Max_sell==23)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
            ui->label_56->lower();
            ui->label_58->lower();
            ui->label_60->lower();
            ui->label_62->lower();
            ui->label_64->lower();
            ui->label_66->lower();
            ui->label_68->lower();
            ui->label_70->lower();
            ui->label_72->lower();
        }
        else if(Max_sell==24)
        {
            ui->label_26->lower();
            ui->label_28->lower();
            ui->label_30->lower();
            ui->label_32->lower();
            ui->label_34->lower();
            ui->label_36->lower();
            ui->label_38->lower();
            ui->label_40->lower();
            ui->label_42->lower();
            ui->label_44->lower();
            ui->label_46->lower();
            ui->label_48->lower();
            ui->label_50->lower();
            ui->label_52->lower();
            ui->label_54->lower();
            ui->label_56->lower();
            ui->label_58->lower();
            ui->label_60->lower();
            ui->label_62->lower();
            ui->label_64->lower();
            ui->label_66->lower();
            ui->label_68->lower();
            ui->label_70->lower();
            ui->label_72->lower();
            ui->label_74->lower();
        }
        sell_toggle=4;
    }
}

void Dashboard::updateProfile()
{
    ui->label->setText(current_user.username);
    ui->textEdit->setText(current_user.description);
    ui->label_19->setText(current_user.age);
    ui->label_9->setText(current_user.username);
    ui->label_12->setText(current_user.id);
    ui->label_14->setText(current_user.password);
    ui->label_21->setText(current_user.age);
    ui->textEdit_2->setText(current_user.description);
    ui->label_130->setText(current_user.email);
    ui->label_131->setText(current_user.phone);
    ui->label_16->setPixmap(QPixmap(current_user.profile_pic));
    ui->label_22->setPixmap(QPixmap(current_user.profile_pic));
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

void Dashboard::closeEvent(QCloseEvent *event)
{
    // Perform your actions before the Dashboard window closes
    carList.saveData();
    L1.saveUser(current_user);

    // Call the base class implementation
    QMainWindow::closeEvent(event);
}

void Dashboard::on_pushButton_9_clicked()
{
    current_user.changeDP();
    updateProfile();
}


void Dashboard::on_pushButton_8_clicked()
{
    current_user.changeDP();
    updateProfile();
}


void Dashboard::on_pushButton_10_clicked()
{
    if(ui->pushButton_10->text()=="change")
    {
        ui->lineEdit->raise();
        ui->pushButton_10->setText("done");
    }
    else{
        QString new_desc= ui->lineEdit->text();
        current_user.description= new_desc;
        updateProfile();
        ui->textEdit_2->raise();
        ui->pushButton_10->setText("change");
    }
}


void Dashboard::on_pushButton_14_clicked()
{
    if(ui->pushButton_14->text()=="change")
    {
        ui->lineEdit_4->raise();
        ui->pushButton_14->setText("done");
    }
    else{
        QString new_name= ui->lineEdit_4->text();
        current_user.username= new_name;
        updateProfile();
        ui->label_9->raise();
        ui->pushButton_14->setText("change");
    }
}


void Dashboard::on_pushButton_13_clicked()
{
    if(ui->pushButton_13->text()=="change")
    {
        ui->lineEdit_2->raise();
        ui->pushButton_13->setText("done");
    }
    else{
        QString new_id= ui->lineEdit_2->text();
        current_user.id= new_id;
        updateProfile();
        ui->label_12->raise();
        ui->pushButton_13->setText("change");
    }
}


void Dashboard::on_pushButton_12_clicked()
{
    if(ui->pushButton_12->text()=="change")
    {
        ui->lineEdit_3->raise();
        ui->pushButton_12->setText("done");
    }
    else{
        QString new_key= ui->lineEdit_3->text();
        current_user.password= new_key;
        updateProfile();
        ui->label_14->raise();
        ui->pushButton_12->setText("change");
    }
}


void Dashboard::on_pushButton_11_clicked()
{
    if(ui->pushButton_11->text()=="change")
    {
        ui->comboBox->raise();
        ui->pushButton_11->setText("done");
    }
    else{
        QString new_age= ui->comboBox->currentText();
        current_user.age= new_age;
        updateProfile();
        ui->label_21->raise();
        ui->pushButton_11->setText("change");
    }
}


void Dashboard::on_pushButton_15_clicked()
{
    if(sell_toggle==0)
    {
        return;
    }
    else if(sell_toggle==1 && sell_move==0)
    {
        sell_move++;
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else if(sell_toggle==2 && sell_move==1)
    {
        sell_move++;
        ui->stackedWidget_2->setCurrentIndex(2);
    }
    else if(sell_toggle==3 && sell_move==2)
    {
        sell_move++;
        ui->stackedWidget_2->setCurrentIndex(3);
    }
    else if(sell_toggle==4 && sell_move==3)
    {
        sell_move++;
        ui->stackedWidget_2->setCurrentIndex(4);
    }
    else
    {
        return;
    }
}


void Dashboard::on_pushButton_16_clicked()
{
    if(sell_toggle==0)
    {
        return;
    }
    else if(sell_toggle==1 && sell_move==1)
    {
        sell_move--;
        ui->stackedWidget_2->setCurrentIndex(0);
    }
    else if(sell_toggle==2 && sell_move==2)
    {
        sell_move--;
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else if(sell_toggle==3 && sell_move==3)
    {
        sell_move--;
        ui->stackedWidget_2->setCurrentIndex(2);
    }
    else if(sell_toggle==4 && sell_move==4)
    {
        sell_move--;
        ui->stackedWidget_2->setCurrentIndex(3);
    }
    else
    {
        return;
    }
}


void Dashboard::on_pushButton_17_clicked()
{
    if(purchase_toggle==0)
    {
        return;
    }
    else if(purchase_toggle==1 && purchase_move==0)
    {
        purchase_move++;
        ui->stackedWidget_3->setCurrentIndex(1);
    }
    else if(purchase_toggle==2 && purchase_move==1)
    {
        purchase_move++;
        ui->stackedWidget_3->setCurrentIndex(2);
    }
    else if(purchase_toggle==3 && purchase_move==2)
    {
        purchase_move++;
        ui->stackedWidget_3->setCurrentIndex(3);
    }
    else if(purchase_toggle==4 && purchase_move==3)
    {
        purchase_move++;
        ui->stackedWidget_3->setCurrentIndex(4);
    }
    else
    {
        return;
    }
}


void Dashboard::on_pushButton_18_clicked()
{
    if(purchase_toggle==0)
    {
        return;
    }
    else if(purchase_toggle==1 && purchase_move==1)
    {
        purchase_move--;
        ui->stackedWidget_3->setCurrentIndex(0);
    }
    else if(purchase_toggle==2 && purchase_move==2)
    {
        purchase_move--;
        ui->stackedWidget_3->setCurrentIndex(1);
    }
    else if(purchase_toggle==3 && purchase_move==3)
    {
        purchase_move--;
        ui->stackedWidget_3->setCurrentIndex(2);
    }
    else if(purchase_toggle==4 && purchase_move==4)
    {
        purchase_move--;
        ui->stackedWidget_3->setCurrentIndex(3);
    }
    else
    {
        return;
    }
}


void Dashboard::on_pushButton_19_clicked()
{
    if(ui->lineEdit_5->text().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Warning, "Email Error", "Can't proceed without Email", QMessageBox::Ok, this);
        msgBox.setStyleSheet("QLabel{ color : white; }");
        msgBox.exec();
    }
    else if(ui->lineEdit_6->text().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Warning, "Phone Error", "Kindly enter your phone number", QMessageBox::Ok, this);
        msgBox.setStyleSheet("QLabel{ color : white; }");
        msgBox.exec();
    }
    else
    {
        QString em=ui->lineEdit_5->text();
        QString ph=ui->lineEdit_6->text();
        QString dis=ui->lineEdit_7->text();
        current_user.email=em;
        current_user.phone=ph;
        current_user.description=dis;
        current_user.status="true";
        updateProfile();
        ui->stackedWidget_4->setCurrentIndex(1);
    }
}


void Dashboard::on_pushButton_20_clicked()
{
    if(ui->pushButton_20->text()=="change")
    {
        ui->lineEdit_8->raise();
        ui->pushButton_20->setText("done");
    }
    else{
        QString new_email= ui->lineEdit_8->text();
        current_user.email= new_email;
        updateProfile();
        ui->label_130->raise();
        ui->pushButton_20->setText("change");
    }
}


void Dashboard::on_pushButton_21_clicked()
{
    if(ui->pushButton_21->text()=="change")
    {
        ui->lineEdit_9->raise();
        ui->pushButton_21->setText("done");
    }
    else{
        QString new_phone= ui->lineEdit_9->text();
        current_user.phone= new_phone;
        updateProfile();
        ui->label_131->raise();
        ui->pushButton_21->setText("change");
    }
}


void Dashboard::on_pushButton_22_clicked()
{
    if (ui->lineEdit_16->text().isEmpty() || ui->lineEdit_10->text().isEmpty() ||
        ui->lineEdit_11->text().isEmpty() || ui->lineEdit_12->text().isEmpty() ||
        ui->lineEdit_13->text().isEmpty() || ui->lineEdit_14->text().isEmpty() || ui->lineEdit_17->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Enter all the data");

    } else {
        QString man = ui->lineEdit_16->text();
        QString ye = ui->lineEdit_10->text();
        QString pr = ui->lineEdit_11->text();
        QString mo = ui->comboBox_2->currentText();
        QString cy = ui->lineEdit_12->text();
        QString fl = ui->lineEdit_13->text();
        QString pai = ui->lineEdit_14->text();
        QString desc = ui->lineEdit_17->text();

        current_car.setValues(pr, ye, mo, man, cy, fl, pai, desc);
        carList.addNode(current_car);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        toggle();
        emptySales();
        fillSales();
        current_user.addCarSold(current_car.id);
        s1.push(current_car.id);
        QMessageBox msgBox(QMessageBox::Information, "Success", "Posted Successfully", QMessageBox::Ok, this);
        msgBox.setStyleSheet("QLabel{ color : white; }");
        Max_sell++;
        msgBox.exec();
        hideSells();
        soldData();
        putSell();
    }

}

void Dashboard::on_pushButton_23_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(1);
}

void Dashboard::on_pushButton_24_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);
}

void Dashboard::refresh_page()
{
    toggle();
    emptySales();
    fillSales();
}

void Dashboard::on_pushButton_25_clicked()
{
    QString id= ui->label_207->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();
    }

}



void Dashboard::on_pushButton_27_clicked()
{
    QString id= ui->label_224->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_29_clicked()
{
    QString id= ui->label_241->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_31_clicked()
{
    QString id= ui->label_258->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_33_clicked()
{
    QString id= ui->label_275->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_35_clicked()
{
    QString id= ui->label_292->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_37_clicked()
{
    QString id= ui->label_309->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_39_clicked()
{
    QString id= ui->label_326->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_41_clicked()
{
    QString id= ui->label_343->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_43_clicked()
{
    QString id= ui->label_360->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_45_clicked()
{
    QString id= ui->label_377->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_47_clicked()
{
    QString id= ui->label_394->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_49_clicked()
{
    QString id= ui->label_411->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }
}

void Dashboard::on_pushButton_51_clicked()
{
    QString id= ui->label_428->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_53_clicked()
{
    QString id= ui->label_445->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }
}

void Dashboard::on_pushButton_55_clicked()
{
    QString id= ui->label_462->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_57_clicked()
{
    QString id= ui->label_479->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_59_clicked()
{
    QString id= ui->label_496->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_61_clicked()
{
    QString id= ui->label_513->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_63_clicked()
{
    QString id= ui->label_530->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();

    }

}

void Dashboard::on_pushButton_65_clicked()
{
    QString id= ui->label_547->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();
    }

}

void Dashboard::on_pushButton_67_clicked()
{
    QString id= ui->label_564->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();
    }

}

void Dashboard::on_pushButton_69_clicked()
{
    QString id= ui->label_581->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();
    }
}

void Dashboard::on_pushButton_71_clicked()
{
    QString id= ui->label_598->text();
    if(current_user.searchPurchase(id))
    {
        QMessageBox::information(this,"Sorry, Unsuccessful!","This Car is put on sale by you.");
    }
    else
    {
        QMessageBox::information(this,"Successfully Purchased!","Thanks for Choosing Us");

        p1.push(id);
        carList.change_status(id);
        q1.refresh();
        q1.add_cars(carList.head);
        totalCarsOnSale= q1.getCount();
        current_user.addCarPurchase(id);
        Max_purchase++;
        hidePurchase();
        purchaseData();
        putPurchase();
    }

}

void Dashboard::on_pushButton_75_clicked()
{
    refresh_page();
}


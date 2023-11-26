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

    //purple #9141d9 blue #263173 white #ffffff
    QObject::connect(ui->pushButton_5, &QPushButton::clicked, [&]() {
        ui->pushButton_5->setStyleSheet("background-color: #9141d9; border: none; color: #ffffff;");
        ui->pushButton_3->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_4->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_6->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->pushButton_7->setStyleSheet("background-color: #263173; border: none; color: #ffffff;");
        ui->stackedWidget->setCurrentIndex(4);
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
        // Handle error opening the file
       // qWarning() << "Error opening file:" << filename;
       // return QString();  // Return an empty string in case of an error
    }

    // Create a QTextStream to read data from the file
    QTextStream inz(&file);

    // Read the content of the file into a QString
    QString userDetails = inz.readLine();
//    QString userid = ui->lineEdit_4->text();
//    QString password = ui->lineEdit_5->text();
//    User temp(userid, password);
    QFile fp("Userdetails.txt");
    if (!fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Handle error opening file
        //return 1;
    }

    QTextStream in(&fp);
    int numberOfObjects = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
//            User* newUser = User::createFromString(line);
        // Add 'newUser' to your dynamic array or linked list
        // (you'll need to manage memory appropriately)
        ++numberOfObjects;
    }

    fp.close();

    User* userArray = new User[numberOfObjects];

        // Read the file again to populate your dynamically allocated object array
    QFile fp1("Userdetails.txt");
    if (!fp1.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Handle error opening file
        delete[] userArray; // Clean up allocated memory
        //return 1;
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
    LinkedList L1;
    for(int i=0; i<numberOfObjects; ++i)
    {
        L1.addNode(userArray[i]);
    }

    current_user= L1.currentid_search(userDetails);
    s1= Stack_sell(current_user);
    p1= Stack_purchase(current_user);
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
    ui->label_16->setPixmap(QPixmap(current_user.profile_pic));
    ui->label_22->setPixmap(QPixmap(current_user.profile_pic));

    // Close the file
    //file.close();

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
    if(Max_sell==-1)
    {
        return;
    }
    if(Max_sell>=0)
    {
        ui->label_25->setText(s1.pop());
    }
    if(Max_sell>=1)
    {
        ui->label_27->setText(s1.pop());
    }
    if(Max_sell>=2)
    {
        ui->label_29->setText(s1.pop());
    }
    if(Max_sell>=3)
    {
        ui->label_31->setText(s1.pop());
    }
    if(Max_sell>=4)
    {
        ui->label_33->setText(s1.pop());
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
    if(Max_purchase==-1)
    {
        return;
    }
    if(Max_purchase>=0)
    {
        ui->label_75->setText(p1.pop());
    }
    if(Max_purchase>=1)
    {
        ui->label_77->setText(p1.pop());
    }
    if(Max_purchase>=2)
    {
        ui->label_79->setText(p1.pop());
    }
    if(Max_purchase>=3)
    {
        ui->label_81->setText(p1.pop());
    }
    if(Max_purchase>=4)
    {
        ui->label_83->setText(p1.pop());
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
        QMessageBox::warning(this,"Email Error","Can't proceed without Email");
    }
    else if(ui->lineEdit_6->text().isEmpty())
    {
        QMessageBox::warning(this,"Phone Error","Kindly enter your phone number");
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
        ui->lineEdit_13->text().isEmpty() || ui->lineEdit_14->text().isEmpty() ||
        ui->lineEdit_15->text().isEmpty() || ui->lineEdit_17->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Enter all the data");

    } else {
        QString man = ui->lineEdit_16->text();
        QString ye = ui->lineEdit_10->text();
        QString pr = ui->lineEdit_11->text();
        QString mo = ui->comboBox_2->currentText();
        QString cy = ui->lineEdit_12->text();
        QString fl = ui->lineEdit_13->text();
        QString pai = ui->lineEdit_14->text();
        QString pos = ui->lineEdit_15->text();
        QString desc = ui->lineEdit_17->text();

        current_car.setValues(pr, ye, mo, man, cy, fl, pai, pos, desc);
        s1.push(current_car.id);
        QMessageBox::information(this, "Success", "Posted Successfully");
    }

}


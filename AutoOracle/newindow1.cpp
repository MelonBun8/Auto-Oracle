#include "newindow1.h"
#include "./ui_newindow1.h"
#include "dashboard.h"
#include "./ui_dashboard.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <iostream>
#include <iomanip>
#include <QMessageBox>
#include <QTimer>

int currentIndex = 0;
void Newindow1::showNewWindow()
{
    Dashboard *newWindow = new Dashboard();
    newWindow->show();
    this->close();
}

//void MainWindow::showNewWindow()
//{
//    Newindow1 *newWindow = new Newindow1;
//    newWindow->show();
//    this->close();
//}
//void Newindow1::showNewWindow2()
//{
//    adminportal *newWindow = new adminportal();
//    newWindow->show();
//    this->close();
//}

Newindow1::Newindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Newindow1)
{
    ui->setupUi(this);
    ui->passlineEdit->setEchoMode(QLineEdit::Password);

    connect(ui->checkBox, &QCheckBox::toggled, this, [this](bool checked) {
    if (checked) {
            ui->passlineEdit->setEchoMode(QLineEdit::Normal);
        }
    else {
            ui->passlineEdit->setEchoMode(QLineEdit::Password);
        }
  });

        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Newindow1::changePictureAndText);

        // Set the timer interval to control the speed of changes (e.g., 3000ms for 3 seconds)
        timer->start(3000);

}

void Newindow1::changePictureAndText() {

    QStringList picturePaths = {
        ":/pic1.jpg",
            ":/pic2.jpg",
            ":/pic3.jpg",
            ":/pic4.jpg"
    };

    QStringList textLabels = {
        "Buy your Dream Car",
        "Become a Seller",
        "Keep up with your Profile",
        "Find Best Price with AI"
    };
            // Update the picture and text labels
            ui->label_6->setPixmap(QPixmap(picturePaths[currentIndex]));

            if(currentIndex==0)
            {
               ui->label_5->setText(textLabels[currentIndex]);
               ui->label_10->setText(" ");
               ui->label_9->setText(" ");
               ui->label_11->setText(" ");
            }
            else if(currentIndex==1)
            {
               ui->label_10->setText(textLabels[currentIndex]);
               ui->label_9->setText(" ");
               ui->label_11->setText(" ");
               ui->label_5->setText(" ");
            }
            else if(currentIndex==2)
            {
               ui->label_9->setText(textLabels[currentIndex]);
               ui->label_10->setText(" ");
               ui->label_11->setText(" ");
               ui->label_5->setText(" ");
            }
            else{
                ui->label_11->setText(textLabels[currentIndex]);
                ui->label_10->setText(" ");
                ui->label_9->setText(" ");
                ui->label_5->setText(" ");
            }

            // Increment the index and loop back to 0 if necessary
            currentIndex = (currentIndex + 1) % picturePaths.size();
        }

Newindow1::~Newindow1()
{
    delete ui;
}


//void Newindow1::on_pushButton_clicked()
//{

//    QFile *fp;
//    QString path1 = "CurrentFlagValue.txt";
//    fp = new QFile(path1);
//    if(!fp->open(QIODevice::WriteOnly | QIODevice::Text))
//        qDebug() << "Could not open file for write";
//    QTextStream out(fp);
//    out.seek(fp->size());
//    out <<"true"<< "\n";
//    fp->close();
//    QString username = ui->namelineEdit->text();
//    QString userid = ui->idlineEdit->text();
//    QString password = ui->passlineEdit->text();
//    if(ui->idlineEdit->text().isEmpty())
//    {
//        QMessageBox::warning(this,"ID Error","Can't proceed without userID");
//    }
//    else if(ui->passlineEdit->text().isEmpty())
//    {
//        QMessageBox::warning(this,"Password Error","Kindly enter a password");
//    }
//    else{
//    QFile *f;
//            QString path = "Userdetails.txt";
//            f = new QFile(path);
//            if(!f->open(QIODevice::ReadWrite | QIODevice::Text))
//                qDebug() << "Could not open file for read/write";

//UserManager user(f);

//    if(ui->logincheck->isChecked())
//        {
//            int res;
//            res = user.checkCredentials(username, userid, password);
//            if(res==1)
//            {
//                QMessageBox::warning(this,"ID Error","UserID has already been taken");
//            }

//            else if(res==2)
//            {

//                QMessageBox::warning(this,"Account Error","Account already present. Enter New Details.");

//            }
//            else if(res==0)
//            {
//                int check;
//                check= user.saveUserDetails(username,userid,password);
//                if(check)
//               {
//                    QMessageBox::information(this,"Signing","Sign Up Succesful");
//                    QFile *file;
//                    QString path = "Currentuserdetails.txt";
//                    file = new QFile(path);
//                    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
//                        qDebug() << "Could not open file for write";
//                    QTextStream out(file);
//                    out.seek(file->size());
//                    out << username<< "\n";
//                    file->close();
//                    showNewWindow();
//                }
//            }
//        }

//    else{

//            int res2=0;
//            res2= user.checkCredentials(username,userid,password);
//            if(res2==2)
//            {
//                QFile *file;
//                QString path = "Currentuserdetails.txt";
//                file = new QFile(path);
//                if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
//                    qDebug() << "Could not open file for write";
//                QTextStream out(file);
//                out.seek(file->size());
//                out << username<< "\n";
//                file->close();
//                showNewWindow();
//            }

//            else if(res2)
//            {
//                QMessageBox::warning(this,"Incorrect Password","Password is wrong! Try Again");
//            }
//            else if(res2==0)
//            {
//                 QMessageBox::warning(this,"Login Error","No Such Account Present!");
//            }
//        }
//}

//}

void Newindow1::on_pushButton_4_clicked()  //for login
{

//    QFile *fp;
//    QString path1 = "CurrentFlagValue.txt";
//    fp = new QFile(path1);
//    if(!fp->open(QIODevice::WriteOnly | QIODevice::Text))
//        qDebug() << "Could not open file for write";
//    QTextStream out(fp);
//    out.seek(fp->size());
//    out <<"true"<< "\n";
//    fp->close();
    //QString username = ui->lineEdit->text();

    if(ui->lineEdit_4->text().isEmpty())
    {
        QMessageBox::warning(this,"ID Error","Can't proceed without userID");
    }
    else if(ui->lineEdit_5->text().isEmpty())
    {
        QMessageBox::warning(this,"Password Error","Kindly enter a password");
    }
    else{
        QString userid = ui->lineEdit_4->text();
        QString password = ui->lineEdit_5->text();
        User temp(userid, password);
        QFile file("Userdetails.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Handle error opening file
            //return 1;
        }

        QTextStream in(&file);
        int numberOfObjects = 0;

        while (!in.atEnd()) {
            QString line = in.readLine();
//            User* newUser = User::createFromString(line);
            // Add 'newUser' to your dynamic array or linked list
            // (you'll need to manage memory appropriately)
            ++numberOfObjects;
        }

        file.close();

        User* userArray = new User[numberOfObjects];

            // Read the file again to populate your dynamically allocated object array
        QFile fp("Userdetails.txt");
        if (!fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Handle error opening file
            delete[] userArray; // Clean up allocated memory
            //return 1;
        }
        QTextStream iny(&fp);
        int currentIndex = 0;
        User temp2;
        while (!iny.atEnd()) {
            QString line1 = iny.readLine();
            User* newUser = temp2.createFromString(line1);
            userArray[currentIndex] = *newUser; // Assuming User is copyable
            ++currentIndex;
        }

        fp.close();
        LinkedList L1;
        for(int i=0; i<numberOfObjects; ++i)
        {
            L1.addNode(userArray[i]);
        }

        if(L1.login_search(temp))
        {
            QFile *fp3;
            QString path = "Currentuserdetails.txt";
            fp3 = new QFile(path);
            if(!fp3->open(QIODevice::WriteOnly | QIODevice::Text))
                qDebug() << "Could not open file for write";
            QTextStream out(fp3);
            out.seek(fp3->size());
            out << userid<< "\n";
            fp3->close();
            QMessageBox::information(this,"Welcome","LogIn Succesful");
            showNewWindow();
        }
        else{
            QMessageBox::warning(this,"Login Error","Please Enter Correct Account Details!");
        }
//        QFile *f;
//            QString path = "Userdetails.txt";
//            f = new QFile(path);
//            if(!f->open(QIODevice::ReadWrite | QIODevice::Text))
//                qDebug() << "Could not open file for read/write";

//        UserManager user(f);

//    if(ui->logincheck->isChecked())
//        {
//            int res;
//            res = user.checkCredentials(username, userid, password);
//            if(res==1)
//            {
//                QMessageBox::warning(this,"ID Error","UserID has already been taken");
//            }

//            else if(res==2)
//            {

//                QMessageBox::warning(this,"Account Error","Account already present. Enter New Details.");

//            }
//            else if(res==0)
//            {
//                int check;
//                check= user.saveUserDetails(username,userid,password);
//                if(check)
//               {
//                    QMessageBox::information(this,"Signing","Sign Up Succesful");
//                    QFile *file;
//                    QString path = "Currentuserdetails.txt";
//                    file = new QFile(path);
//                    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
//                        qDebug() << "Could not open file for write";
//                    QTextStream out(file);
//                    out.seek(file->size());
//                    out << username<< "\n";
//                    file->close();
//                    showNewWindow();
//                }
//            }
//        }

//    else{

//            int res2=0;
//            res2= user.checkCredentials(username,userid,password);
//            if(res2==2)
//            {
//                QFile *file;
//                QString path = "Currentuserdetails.txt";
//                file = new QFile(path);
//                if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
//                    qDebug() << "Could not open file for write";
//                QTextStream out(file);
//                out.seek(file->size());
//                out << username<< "\n";
//                file->close();
//                showNewWindow();
//            }

//            else if(res2)
//            {
//                QMessageBox::warning(this,"Incorrect Password","Password is wrong! Try Again");
//            }
//            else if(res2==0)
//            {
//                 QMessageBox::warning(this,"Login Error","No Such Account Present!");
//            }
//        }
    }

}

//void Newindow1::on_pushButton_2_clicked()
//{
//    showNewWindow2();
//}




void Newindow1::on_pushButton_3_clicked()  //sign up
{
//    QFile *fp;
//    QString path1 = "CurrentFlagValue.txt";
//    fp = new QFile(path1);
//    if(!fp->open(QIODevice::WriteOnly | QIODevice::Text))
//        qDebug() << "Could not open file for write";
//    QTextStream out(fp);
//    out.seek(fp->size());
//    out <<"true"<< "\n";
//    fp->close();
    //QString username = ui->lineEdit->text();

    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty())
    {
        QMessageBox::warning(this,"Sign Up Error","Kindly Enter all the required fields");
    }
//    else if(ui->passlineEdit->text().isEmpty())
//    {
//        QMessageBox::warning(this,"Password Error","Kindly enter a password");
//    }
    else{
        QString username = ui->lineEdit->text();
        QString userid = ui->lineEdit_2->text();
        QString password = ui->lineEdit_3->text();
        QString age= ui->comboBox->currentText();

        User temp(username, userid, password, age);
        QFile file("Userdetails.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Handle error opening file
            //return 1;
        }

        QTextStream in(&file);
        int numberOfObjects = 0;

        while (!in.atEnd()) {
            QString line = in.readLine();
//            User* newUser = User::createFromString(line);
            // Add 'newUser' to your dynamic array or linked list
            // (you'll need to manage memory appropriately)
            ++numberOfObjects;
        }

        file.close();

        User* userArray = new User[numberOfObjects];

            // Read the file again to populate your dynamically allocated object array
        QFile fp("Userdetails.txt");
        if (!fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Handle error opening file
            delete[] userArray; // Clean up allocated memory
           // return 1;
        }
        QTextStream iny(&fp);
        int currentIndex = 0;
        User temp3;
        while (!iny.atEnd()) {
            QString line1 = iny.readLine();
            User* newUser = temp3.createFromString(line1);
            userArray[currentIndex] = *newUser; // Assuming User is copyable
            ++currentIndex;
        }

        fp.close();
        LinkedList L1;
        for(int i=0; i<numberOfObjects; ++i)
        {
            L1.addNode(userArray[i]);
        }

        if(L1.signup_search(temp))
        {
            QFile fp2("Userdetails.txt");
           // QString path = ;
           // file = new QFile(path);
            if(!fp2.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Append ))
                qDebug() << "Could not open file for write";
            QTextStream out(&fp2);
            out.seek(fp2.size()); // Move to end of file
            out << temp.username  << ";" << temp.id << ";" << temp.password << ";" << temp.description<< ";" << temp.profile_pic<< ";" << temp.age<< ";"<< temp.status<<";"<<temp.phone<<";"<<temp.email<<";";
            for(int i=0; i<25; i++)
            {
                out<< temp.cars_purchased[i]<<",";
            }
            out<<";";
            for(int i=0; i<25; i++)
            {
                out<< temp.cars_sold[i]<<",";
            }
            out<<"\n";
            fp2.close();

            QFile *fp3;
            QString path = "Currentuserdetails.txt";
            fp3 = new QFile(path);
            if(!fp3->open(QIODevice::WriteOnly | QIODevice::Text))
                qDebug() << "Could not open file for write";
            QTextStream out1(fp3);
            out1.seek(fp3->size());
            out1 << userid<< "\n";
            fp3->close();
            QMessageBox::information(this,"Signing","Sign Up Succesful");
            showNewWindow();
        }
        else
        {
            QMessageBox::warning(this,"ID Error","UserID has already been taken");
        }
    }
}


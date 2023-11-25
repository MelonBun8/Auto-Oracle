#ifndef NEWINDOW1_H
#define NEWINDOW1_H

#include <QMainWindow>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <iostream>
#include <iomanip>
#include <QMessageBox>
#include <QtGlobal>
#include <QDebug>

namespace Ui {
class Newindow1;
}

class Newindow1 : public QMainWindow
{
    Q_OBJECT
    QString username;

public:
    explicit Newindow1(QWidget *parent = nullptr);
    ~Newindow1();
    QDialog *newWindow;

public slots:
    void showNewWindow();
//    void showNewWindow2();
    void changePictureAndText();

private slots:
    //void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Newindow1 *ui;
};

class User{
public:
    QString username;
    QString id;
    QString password;
    QString description;
    QString profile_pic;
    QString age;
    QString status;
    QString phone;
    QString email;
    QString cars_purchased[25];
    QString cars_sold[25];

    User() //for login
    {
        username= "-";
        id= "-";
        password= "-";
        description= "-";
        profile_pic= ":/profile_pic1.jpg";
        age = "-";
        status= "false";
        phone= "-";
        email= "-";
        for(int i=0; i<25; i++)
        {
            cars_purchased[i]="-";
            cars_sold[i]="-";
        }
    }

    User(QString enter_id, QString enter_pass) //for login
    {
        username= "-";
        id= enter_id;
        password= enter_pass;
        description= "-";
        profile_pic= "-";
        age = "-";
        status= "false";
        phone= "-";
        email= "-";
        for(int i=0; i<25; i++)
        {
            cars_purchased[i]="-";
            cars_sold[i]="-";
        }
    }

    User(QString enter_name, QString enter_id, QString enter_pass, QString enter_age) //for signup
    {
        username= enter_name;
        id= enter_id;
        password= enter_pass;
        description= "-";
        profile_pic= ":/profile_pic1.jpg";
        age = enter_age;
        status= "false";
        phone= "-";
        email= "-";
        for(int i=0; i<25; i++)
        {
            cars_purchased[i]="-";
            cars_sold[i]="-";
        }
    }


    User* createFromString(const QString& line) {
        QStringList parts = line.split(';'); // Assuming ';' separates attributes

        if (parts.size() != 11) {
            // Handle invalid input format
            return nullptr;
        }

        User* newUser = new User("-","-");
        newUser->username = parts[0].trimmed();
        newUser->id = parts[1].trimmed();
        newUser->password = parts[2].trimmed();
        newUser->description = parts[3].trimmed();
        newUser->profile_pic = parts[4].trimmed();
        newUser->age = parts[5].trimmed();
        newUser->status= parts[6].trimmed();
        newUser->phone= parts[7].trimmed();
        newUser->email= parts[8].trimmed();

        QStringList purchasedCars = parts[9].trimmed().split(',');
        for (int i = 0; i < qMin(purchasedCars.size(), 25); ++i) {
            newUser->cars_purchased[i] = purchasedCars[i];
        }

        QStringList soldCars = parts[10].trimmed().split(',');
        for (int i = 0; i < qMin(soldCars.size(), 25); ++i) {
            newUser->cars_sold[i] = soldCars[i];
        }
        // You can do a similar parsing for cars_sold if needed

        return newUser;
    }

    void changeDP()
    {
        if(profile_pic==":/profile_pic1.jpg")
        {
            profile_pic= ":/profile_pic2.jpg";
        }
        else
        {
            profile_pic= ":/profile_pic1.jpg";
        }
    }
};

class Node {
public:
    User data;
    Node* next;

    Node(const User& userData) : data(userData), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to add a new node to the linked list (Add to Head)
    void addNode(const User& userData) {
        Node* newNode = new Node(userData);
        newNode->next = head;
        head = newNode;
    }

    // Function to display the linked list
//    void displayList() {
//        Node* current = head;
//        while (current != nullptr) {
//            std::cout << current->data.username << " ";
//            // Output other data members as needed...
//            current = current->next;
//        }
//        std::cout << std::endl;
//    }

    bool login_search(const User& userData)
    {
        Node* n= new Node(userData);
        Node* temp= head;
        while(temp!=NULL)
        {
            if(temp->data.id==n->data.id && temp->data.password==n->data.password)
            {

                return true;
            }
            if(temp->data.id==n->data.id && temp->data.password!=n->data.password)
            {
               // QMessageBox::warning(this,"Incorrect Password","Password is wrong! Try Again");
                return false;
            }
            temp= temp->next;
        }

        return false;

    }

    bool signup_search(const User& userData)
    {
        Node* n= new Node(userData);
        Node* temp= head;
        while(temp!=NULL)
        {
            if(temp->data.id==n->data.id)
            {

                return false;
            }
            temp= temp->next;
        }

        return true;

    }

    User currentid_search(QString search_id)
    {
        Node* temp= head;
        while(temp!=NULL)
        {
            if(temp->data.id==search_id)
            {
                return temp->data;
            }
            temp= temp->next;
        }
        return temp->data;
    }


};

class Stack_sell
{

public:
      //User *User_obj;
      int top1;
      int restore1;
      QString storage[25];

      Stack_sell()
      {
          top1=-1;
          restore1=-1;
          for(int i=0; i<25; i++)
          {
              storage[i]= "-";
          }
      }
      Stack_sell(User obj)
      {
            top1 = -1;
            restore1= -1;
            int i=0;
            while(obj.cars_sold[i]!="-")
            {
                storage[i]= obj.cars_sold[i];
                qDebug() << storage[i];
                i++;
                top1= top1+1;

            }
            restore1= top1;
//            for(int i=0;i<User_obj->cars_sold[50].length();i++)
//            {
//            	storage[i]=User_obj->cars_sold[50][i];
//              top++;
//              restore++;
//			}
      }

      int getRestore1()
      {
          return restore1;
      }

      bool isFull()
      {
            return (top1 >= 25);
      }

      bool isEmpty()
      {
            return (top1 == -1);
      }

      void rest ()
      {
        top1=restore1;
      }

      QString pop()
      {
            if (isEmpty())
            {
                //cout<<"Stack is empty";
                return "-";
            }
            QString value= storage[top1];
            top1--;
            return value;

      }

      QString peek()
      {
            if (isEmpty())
            {
                //cout<<"Stack is empty";
            }

            return (storage[top1]);
      }

      void push(QString add_purchase)
      {
        if(isFull())
        {
            //cout<<"Stack is full";
        }
        if(isEmpty())
        {
            rest();
        }
        storage[++top1]=add_purchase;
//		User_obj->cars_sold[++top]=add_purchase;
      }

//	  ~Stack_purchase()
//	  {
//	  	delete(User_obj);
//	  }


};

class Stack_purchase
{

public:
      //User *User_obj;
      int top2;
      int restore2;
      QString storage2[25];

      Stack_purchase()
      {
          top2= -1;
          restore2= -1;
          for(int i=0; i<25; i++)
          {
              storage2[i]= "-";
          }
      }
      Stack_purchase(User obj)
      {
            top2 = -1;
            restore2= -1;
            int i=0;
            while(obj.cars_purchased[i]!="-")
            {
                storage2[i]= obj.cars_purchased[i];
                qDebug() << storage2[i];
                i++;
                top2= top2+1;


            }
            restore2= top2;
            qDebug()<< restore2;


      }

      int getRestore2()
      {
          return restore2;
      }

      bool isFull()
      {
            return (top2 >= 25);
      }

      bool isEmpty()
      {
            return (top2 == -1);
      }

      void rest ()
      {
        top2=restore2;
      }

      QString pop()
      {
            if (isEmpty())
            {
                //cout<<"Stack is empty";
                return "-";
            }
            QString value=  storage2[top2];
            top2--;
            return value;
      }

      QString peek()
      {
            if (isEmpty())
            {
                //cout<<"Stack is empty";
            }

            return (storage2[top2]);
      }

      void push(QString add_purchase)
      {
        if(isFull())
        {
            //cout<<"Stack is full";
        }
        if(isEmpty())
        {
            rest();
        }
        storage2[++top2]=add_purchase;
//		User_obj->cars_purchased[++top]=add_purchase;
      }




};


class UserManager {
public:
    UserManager(QFile *f ){
        file = f;

    }

    int checkCredentials(QString username, QString userid, QString password) {
        QTextStream in(file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");

            if(parts[1]==userid && parts[2]==password)
            {
                return 2;
            }
            else if(parts[1] == userid )
            {
                return 1;
            }
        }
        return 0;
    }

    bool saveUserDetails(QString username,QString userid, QString password) {

        QTextStream out(file);
        out.seek(file->size()); // Move to end of file
        out << username << "," << userid << "," << password << "\n";
        return true;
    }

    ~UserManager() {
        file->close();
    }

public:
    QFile* file;
};


#endif // NEWINDOW1_H

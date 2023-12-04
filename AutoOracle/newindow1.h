#ifndef NEWINDOW1_H
#define NEWINDOW1_H

#include <QMainWindow>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <iostream>
#include <vector>
#include <iomanip>
#include <QString>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QLocale>

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
    void changePictureAndText();

private slots:

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
        QStringList parts = line.split(';');

        if (parts.size() != 11) {
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

    void addCarSold(QString id)
    {
        int i=0;
        while(cars_sold[i]!="-")
        {
            i++;
        }
        cars_sold[i]=id;
    }

    void addCarPurchase(QString id)
    {
        int i=0;
        while(cars_purchased[i]!="-")
        {
            i++;
        }
        cars_purchased[i]=id;
    }

    bool searchPurchase(QString id)
    {
        int i=0;
        while(cars_sold[i]!="-")
        {
            if(cars_sold[i]==id)
            {
                return true;
            }
            i++;
        }
        return false;
    }
};



class Car {
public:
    QString id;
    QString price;
    QString year;
    QString manufacture;
    QString model;
    QString cylinders;
    QString fuel;
    QString paint_color;
    QString status;
    QString discription;
    QString pic;


    // Default Constructor
    Car() {
        id = id_value();
        price = "-";
        year = "-";
        manufacture = "-";
        model = "-";
        cylinders = "-";
        fuel = "-";
        paint_color = "-";
        status= "false";
        discription = "-";
        pic= "-";
    }

    // Parameterized Constructor
    Car(QString enter_price, QString enter_year, QString enter_manufacture, QString enter_model,
        QString enter_cylinder, QString enter_fuel, QString enter_paint_color, QString enter_dispription) {
        id = id_value();
        price = enter_price;
        year = enter_year;
        manufacture = enter_manufacture;
        model = enter_model;
        cylinders = enter_cylinder;
        fuel = enter_fuel;
        paint_color = enter_paint_color;
        status= "false";
        discription = enter_dispription;
        pic= changePic();
    }

    QString changePic()
    {
        if(manufacture=="Camaro")
        {
            return ":/camaro.jpg";
        }
        else if(manufacture=="Tata Nexon")
        {
            return ":/tata_nexon.jpg";
        }
        else if(manufacture=="Camry")
        {
            return ":/camry.jpg";
        }
        else if(manufacture=="Yaris")
        {
            return ":/yaris.jpg";
        }
        else if(manufacture=="Hyundai Venue")
        {
            return ":/hyundai_venue.jpg";
        }
        else if(manufacture=="Ford Escape")
        {
            return ":/ford_escape.jpg";
        }
        else if(manufacture=="Volkswagen Beetle")
        {
            return ":/volkswagen.jpg";
        }
        else if(manufacture=="Passat")
        {
            return ":/passat.jpg";
        }
        else if(manufacture=="Toyota RAV4")
        {
            return ":/toyota_rav4.jpg";
        }
        else if(manufacture=="Civic")
        {
            return ":/civic.jpg";
        }
        else if(manufacture=="Prius")
        {
            return ":/prius.jpg";
        }
        else if(manufacture=="BMW 5 Series")
        {
            return ":/bmw5_series.jpg";
        }
        else if(manufacture=="Toyota Fortuner")
        {
            return ":/toyota_fortuner.jpg";
        }
        else if(manufacture=="Ford Mustang")
        {
            return ":/ford_mustang.jpg";
        }
        else if(manufacture=="Corolla")
        {
            return ":/corolla.jpg";
        }
        else{
            return "-";
        }
    }

    // Parsing Function
    static Car* carcreateFromString(const QString& line) {
        QStringList parts = line.split(';');

        if (parts.size() != 11) {
            return nullptr;
        }

        Car* newCar = new Car("-", "-", "-", "-", "-", "-", "-", "-");

        newCar->id = parts[0].trimmed();
        newCar->price = parts[1].trimmed();
        newCar->year = parts[2].trimmed();
        newCar->manufacture = parts[3].trimmed();
        newCar->model = parts[4].trimmed();
        newCar->cylinders = parts[5].trimmed();
        newCar->fuel = parts[6].trimmed();
        newCar->paint_color = parts[7].trimmed();
        newCar->status= parts[8].trimmed();
        newCar->discription = parts[9].trimmed();
        newCar->pic= parts[10].trimmed();

        return newCar;
    }

    void setValues(QString enter_price, QString enter_year, QString enter_manufacture,
                   QString enter_model, QString enter_cylinder, QString enter_fuel,
                   QString enter_paint_color, QString enter_description) {
        id = id_value();
        price = enter_price;
        year = enter_year;
        manufacture = enter_manufacture;
        model = enter_model;
        cylinders = enter_cylinder;
        fuel = enter_fuel;
        paint_color = enter_paint_color;
        status= "false";
        discription = enter_description;
        pic= changePic();
    }

    QString id_value() {
        QString randomId = "ID" + QString::number(QRandomGenerator::global()->generate());
        return randomId;
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

    void saveUser(User obj)
    {
        QFile fp("newUser.txt");
        fp.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out1(&fp);
        Node* temp= head;
        while(temp!=NULL)
        {
            if(temp->data.id!=obj.id)
            {
                out1<<temp->data.username<<";"<<temp->data.id<<";"<<temp->data.password<<";"<<temp->data.description<<";"<<temp->data.profile_pic<<";"<<temp->data.age<<";"<<temp->data.status<<";"<<temp->data.phone<<";"<<temp->data.email<<";";
                for(int i=0; i<25; i++)
                {
                    out1<<temp->data.cars_purchased[i]<<",";
                }
                out1<<";";
                for(int j=0; j<25; j++)
                {
                    out1<<temp->data.cars_sold[j]<<",";
                }
                out1<<"\n";
            }
            temp= temp->next;
        }

        out1<<obj.username<<";"<<obj.id<<";"<<obj.password<<";"<<obj.description<<";"<<obj.profile_pic<<";"<<obj.age<<";"<<obj.status<<";"<<obj.phone<<";"<<obj.email<<";";
        for(int i=0; i<25; i++)
        {
            out1<<obj.cars_purchased[i]<<",";
        }
        out1<<";";
        for(int j=0; j<25; j++)
        {
            out1<<obj.cars_sold[j]<<",";
        }
        out1<<"\n";

        fp.close();

        QString oldfile= "Userdetails.txt";

        QFile::remove(oldfile);
        QFile::rename("newUser.txt",oldfile);
    }


};

class Node2 {
public:
    Car data;
    Node2* next;

    Node2(const Car& userData) : data(userData), next(nullptr) {}
};

class LinkedList2 {
public:
    Node2* head;

    LinkedList2() : head(nullptr) {}

    // Function to add a new node to the linked list (Add to Head)
    void addNode(const Car& userData) {
        Node2* newNode = new Node2(userData);
        newNode->next = head;
        head = newNode;
    }

    void saveData()
    {
        QFile file("newFile.txt");
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);

        Node2* temp= head;
        while(temp!=NULL)
        {
            out<<temp->data.id<<";"<<temp->data.price<<";"<<temp->data.year<<";"<<temp->data.manufacture<<";"<<temp->data.model<<";"<<temp->data.cylinders<<";"<<temp->data.fuel<<";"<<temp->data.paint_color<<";"<<temp->data.status<<";"<<temp->data.discription<<";"<<temp->data.pic<<"\n";
            temp= temp->next;
        }

        file.close();
        QString oldfilen= "Cardetails.txt";

        QFile::remove(oldfilen);
        QFile::rename("newFile.txt",oldfilen);
    }

    Car currentid_search2(QString search_id)
    {
        Node2* temp= head;
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

    void change_status(QString search_id)
    {
        Node2* temp= head;
        while(temp!=NULL)
        {
            if(temp->data.id==search_id)
            {
                temp->data.status="true";
            }
            temp= temp->next;
        }
    }

};
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
class Car_Queue{
    QString arr[24];
    int front=-1,rear=-1;
    int count=0;

public:

    Car_Queue()
    {
        for(int i=0; i<24; i++)
        {
            arr[i]="-";
        }
    }

    void add_cars(Node2 *head1)
    {
        Node2* temp= head1;
        while(temp!=NULL)
        {
            if(temp->data.status=="false")
            {
                enqueue(temp->data.id);
            }
            temp= temp->next;
        }
    }

    void refresh()
    {
        for(int i=0; i<24; i++)
        {
            arr[i]="-";
        }
        front=-1;
        rear=-1;
        count=0;
    }
    bool isFull()
    {
        return (rear==24-1);
    }

    bool isEmpty()
    {
        return (front==-1 || front>rear);
    }

    void enqueue(QString id)
    {
       if(isFull())
       {
           return;
       }
       if(front==-1)
       {
           front=0;
       }
       arr[++rear]=id;
       count++;
    }

    QString dequeue()
    {
        if(isEmpty())
        {
            return " ";
        }
        count--;
        return arr[front++];

    }

    int getCount()
    {
        return count;
    }
};
//%%%%%%%%%%%%%%%%%%%%%%________________________________%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
class Car_Stack{
    std::vector<Node2*> carArr;//stack will be of Car Node datatype as we need ALL the data
    int count=0;

public:

    Car_Stack()
    {
    }

    void add_cars(Node2 *head2)
    {
        Node2* temp= head2;
        while(temp!=NULL)
        {
            if(temp->data.status=="false")
            {
                push(temp);
            }
            temp= temp->next;
        }
    }

    void refresh()
    {
        carArr.clear();
        count=0;
    }

    void push(Node2* aNode)
    {
        if(carArr.size()==24)
        {
            return;
        }
        carArr.push_back(aNode);
        count++;
    }

    Node2* pop()
    {
        if(carArr.empty()==true)
        {
            return NULL;
        }
        count--;
        Node2* myNode = carArr.back();//top of stack returned
        carArr.pop_back();
        return myNode;
    }

    int getCount()
    {
        return count;
    }

    int searchColor(int total, QString targetColor){
        for (std::vector<Node2*>::iterator it = carArr.begin(); it != carArr.end();) {
            if ((*it)->data.paint_color != targetColor) {
                it = carArr.erase(it);
                total -= 1;
            }
            else {
                ++it;
            }
        }
        return total;
    }

    int searchCylin(int total, QString targetCylin){
        for (std::vector<Node2*>::iterator it = carArr.begin(); it != carArr.end();) {
            if ((*it)->data.cylinders != targetCylin) {
                it = carArr.erase(it);
                total -= 1;
            }
            else {
                ++it;
            }
        }
        return total;
    }

    int searchBrand(int total, QString targetBrand){
        for (std::vector<Node2*>::iterator it = carArr.begin(); it != carArr.end();) {
            if ((*it)->data.manufacture != targetBrand) {
                it = carArr.erase(it);
                total -= 1;
            }
            else {
                ++it;
            }
        }
        return total;
    }

    void sortFuel(){
        int n = carArr.size();
        bool swapped;
        for (int i = 0; i < n - 1; ++i) {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if ((carArr[j]->data.fuel).compare((carArr[j+1]->data.fuel)) > 0) {
                    // Swap vec[j] and vec[j + 1]
                    std::swap(carArr[j], carArr[j + 1]);
                    swapped = true;
                }
            }

            // If no two elements were swapped in the inner loop, the array is sorted
            if (!swapped) {
                break;
            }
        }
    }

    void sortPrice(){
        int n = carArr.size();
        bool swapped;
        for (int i = 0; i < n - 1; ++i) {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if ((carArr[j]->data.price).compare((carArr[j+1]->data.price)) > 0) {
                    // Swap vec[j] and vec[j + 1]
                    std::swap(carArr[j], carArr[j + 1]);
                    swapped = true;
                }
            }

            // If no two elements were swapped in the inner loop, the array is sorted
            if (!swapped) {
                break;
            }
        }
    }

    void sortYear(){
        int n = carArr.size();
        bool swapped;
        for (int i = 0; i < n - 1; ++i) {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if ((carArr[j]->data.year).compare((carArr[j+1]->data.year)) > 0) {
                    // Swap vec[j] and vec[j + 1]
                    std::swap(carArr[j], carArr[j + 1]);
                    swapped = true;
                }
            }

            // If no two elements were swapped in the inner loop, the array is sorted
            if (!swapped) {
                break;
            }
        }
    }


};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

class Stack_sell
{

public:
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
                i++;
                top1= top1+1;

            }
            restore1= top1;
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
                return "-";
            }

            return (storage[top1]);
      }

      void push(QString add_purchase)
      {
        if(isFull())
        {
            return;
        }

        storage[++top1]=add_purchase;
        ++restore1;
      }


};

class Stack_purchase
{

public:
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
                i++;
                top2= top2+1;


            }
            restore2= top2;


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
                return "-";
            }

            return (storage2[top2]);
      }

    void push(QString add_purchase)
    {
    if(isFull())
    {
        return;
    }

    storage2[++top2]=add_purchase;
    ++restore2;
    }

};

class Price{
public:

    int price;
    Price* next;

    Price(QString p)
    {
        QLocale locale;
        price = locale.toInt(p);
        next = NULL;
    }
};

class Hashtable{
       public:
    Price* table[205];

    Hashtable()
    {
        for(int i=0; i<205; i++)
        {
            table[i]=NULL;
        }
    }

    int hashFunction(const QString& key) {
        std::string copy= key.toStdString();
        int hash = 0;

        hash = copy[0]+ copy[copy.length()-1];
        return hash;
    }

    void insert(QString key, QString value)
    {
        int index= hashFunction(key);
        qDebug()<<index<<"\n";
        Price* newNode= new Price(value);

        if(table[index]==NULL)
        {
            table[index]= newNode;
        }
        else
        {
            Price* temp= table[index];
            while(temp->next!=NULL)
            {
                temp= temp->next;
            }
            temp->next= newNode;
        }
    }
    int search(const QString &model)
    {
        int average = 0;
        int index = hashFunction(model);

        Price *temp = table[index];
        int count = 0;

        while (temp != NULL)
        {
            average += temp->price;
            count++;
            temp = temp->next;
        }
        if (count > 0)
        {
            average /= count;
        }
        return average;
    }

};


#endif // NEWINDOW1_H

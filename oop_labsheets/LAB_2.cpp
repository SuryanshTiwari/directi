#include "bits/stdc++.h"
using namespace std;

class Base{
    //item and name both have two common properties name and id
protected:
    string Name;
    string Id;

public:
    void setName(string name){Name = name;}
    void setId(string id){Id = id;}

    string getName(){return Name;}
    string getId(){return Id;}
};

class Item : public Base{
private:
    int itemQuantity;
    double itemPrice;
public:
    Item(){
        itemPrice = 500;
        itemQuantity = 1;
    }
    //getters and setters
    void setQuantity(int quantity){itemQuantity = quantity;}
    void setPrice(double price){itemPrice = price;}

    int getQuantity(){return itemQuantity;}
    double getPrice(){return itemPrice;}

};

class customer : public Base{
private:
    double Custbalance;
    Item Custitem;
public:
    customer(){
        Custbalance = 5000;
    }
    //getters and setters
    void setbalance(double balance){Custbalance = balance;}

    double getbalance(){return Custbalance;}

    void print(){
        cout << Custitem.getName() << " " << Custitem.getId() << " " << Custitem.getQuantity() << " " << Custitem.getPrice() << "\n";
        Custbalance -= Custitem.getQuantity()*Custitem.getPrice();
        cout << Custbalance << "\n";
    }

    void buyItem(Item item){
        if(Custbalance < (item.getQuantity()*item.getPrice())){
            cout << "Insufficient Balance for " << item.getName() << "\n"; 
            return ;
        }
        if(item.getQuantity() < 1){
            cout << "order not valid";
            return;
        }
        Custitem = item;
        print();
    }
};

int main(int argc, char const *argv[])
{
    customer harsh;
    harsh.setName("harsh");
    harsh.setId("23");

    Item item1;
    item1.setName("mobile");
    item1.setId("44");
     
    harsh.buyItem(item1);

    Item item2;
    item2.setName("speakers");
    item2.setId("F&D");
    item2.setQuantity(2);
    item2.setPrice(1000);
        
    harsh.buyItem(item2);


    return 0;
}
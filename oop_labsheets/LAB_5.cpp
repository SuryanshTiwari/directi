// camelCase for variable names , snake_case for functions , class name
#include "bits/stdc++.h"
using namespace std;

class Address{
public:
    string line1;
    string line2;
    string line3;
    string city;
    string state;
    string pin;

public:
    Address(){
        string some;
        some = line1  + '$' + line2  + '$' + line3  + '$' + city  + '$' + state  + '$' + pin ;
    }

    string get_city(){
        return city;
    }
};


class address_list{
public:
    static int count_address_with_city(vector<Address> addressList, string city){
        int c = -1;
        for(int i = 0; i < addressList.size(); i++){
            if(addressList[i].get_city() == city)c++;
        }
        if(c == -1)
            return -1;
        else
            return c+1;
    }
};

int main(int argc, char const *argv[])
{
    vector<Address> addressList;
    
    Address add1, add2;
    add1.city = "MUMBAI";
    add2.city = "LUCKNOW";

    addressList.push_back(add1);
    addressList.push_back(add2);

    cout <<  address_list::count_address_with_city(addressList, "MUMBAI");
    return 0;
}
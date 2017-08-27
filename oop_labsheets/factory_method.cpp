#include "bits/stdc++.h"
using namespace std;

enum vehicleType{
    VT_TwoWheeler,    VT_ThreeWheeler,    VT_FourWheeler
};

class vehicle{
public:
    virtual void printVehicle(){
        cout << "this is main";
    }
    static vehicle& callvehicle(vehicleType type);
};

class twowheeler:public vehicle{
public:
    void printVehicle(){
        cout << "this is TwoWheeler";
    }
};
class threewheeler:public vehicle{
public:
    void printVehicle(){
        cout << "this is threeWheeler";
    }
};
class fourwheeler:public vehicle{
public:
    void printVehicle(){
        cout << "this is fourWheeler";
    }
};

vehicle vehicle::callvehicle(vehicleType type){
    
    if(type == VT_FourWheeler){
        fourwheeler x;
        // vehicle &btr = x;
        return x;
    }
    else if(type == VT_TwoWheeler){
        twowheeler x ;
        return x;
    }
    else{
        threewheeler x;     
        return x;
    }
}

class client{
private:
    vehicle call;
public:
    client(){
        vehicleType type = VT_FourWheeler;
        vehicle call = vehicle::callvehicle(type); //object slicing occurs, try using pointers
        // ret = ca/ll;
    }
    vehicle getvehicle(){
        return call;
    }
};

int main(int argc, char const *argv[])
{
    client pClient;
    vehicle  pVehicle = pClient.getvehicle();
    pVehicle.printVehicle();
    return 0;
}
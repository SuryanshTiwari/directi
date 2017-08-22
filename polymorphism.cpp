#include "bits/stdc++.h"
using namespace std;

class Person{
public:
	virtual void introduce(){
		cout << "das";
	}
};

class Student: public Person{
public:
	void introduce(){
		cout << "DAs";
	}
};


class Farmer: public Person{
public:
	void introduce(){
		cout << "ads";
	}
};

void print(Person &st){  // late time binding / run time polymorphism / points to a reference of object created
	st.introduce();
}

//Virtual functions allow us to create a list of base class pointers and call methods of any of the derived classes without even knowing kind of derived class object.
//Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.
//They are mainly used to achieve Runtime polymorphism
//Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
//Runtime polymorphism is achieved only through a pointer (or reference) of base class type. Also, a base class pointer can point to the objects of base class as well as to the objects of derived class. In above code, base class pointer ‘bptr’ contains the address of object ‘d’ of derived class.

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	if(n == 0){
		Student st;
		print(st);
	}
	else if(n == 1){
		Farmer st;
		print(st);
	}
	else if(n == 2){
		Person st;
		print(st);
	}
	return 0;
}
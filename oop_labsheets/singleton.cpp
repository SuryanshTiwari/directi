#include "bits/stdc++.h"
using namespace std;

class singleton{
private:
	static singleton* obj;
	singleton(){}
	int c = 0;	
public:
	static singleton*  getInstance(){
		if(obj == NULL){
			obj = new singleton();
		}
		return obj;
	}
	void print(){ //just for testing if only one object is being created
		c++;
		cout << c << "\n";
	}
};

singleton* singleton::obj = NULL;
int main(int argc, char const *argv[])
{
	singleton* oop = singleton::getInstance();
	singleton *k = singleton::getInstance();
	oop->print();
	k->print();
	return 0;
}
	//implementing the pizza example in c++

	#include "bits/stdc++.h"
	using namespace std;

	class Pizza{
	protected:
		string description = "";
		int cost = 0;
	public:
		string getdescription(){
			return description;
		}
		int getcost(){
			return cost;
		}
	};
	
	//decorator
	class Toppingsdecorator:public Pizza{

	};

	//pizzas
	class PeppyPaneer: public Pizza{
	public:
		PeppyPaneer(){
			cost = 100;
			description = description + " PeppyPaneer";
		}
	};
	class Magharita: public Pizza{
	public:
		Magharita(){
			cost = 200;
			description = description + " Magharita";
		}
	};

	//toppings
	class Barbeque: public Toppingsdecorator{
	public:
		Barbeque(Pizza *pizza){
			cost = pizza->getcost() + 50;
			description = pizza->getdescription()+ " Barbeque";
		}
	};

	class Paneer: public Toppingsdecorator{
	public:
		Paneer(Pizza *pizza){
			cost = pizza->getcost() + 60;
			description = pizza->getdescription() + " Paneer";
		}
	};


	int main(){

		Pizza *pizza = new PeppyPaneer();
		cout << pizza->getcost() << " " << pizza->getdescription() << "\n";

		pizza = new Barbeque(pizza);
		cout << pizza->getcost() << " " << pizza->getdescription() << "\n";	

		pizza = new Paneer(pizza);
		cout << pizza->getcost() << " " << pizza->getdescription() << "\n";

		Pizza *pizza2 = new Magharita();
		cout << pizza2->getcost() << " " << pizza2->getdescription() << "\n";		
		return 0;
	}
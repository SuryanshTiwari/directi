#include "bits/stdc++.h"
using namespace std;


class stak{
public:
	int a[100000];
	int c;
	stak(){
		c = 0;
		memset(a, 0, sizeof a);
	}
	void push(int val){
		a[c] = val;
		c++;
	}
	int top(){
		return a[c-1];
	}
	bool pop(){
		if(c == 0)
			return false;
		c--;
		return true;
	}
	void display(){
		for(int i = c-1; i >= 0; i--){
			cout << a[i] << "\n";
		}
	}
};

int main(int argc, char const *argv[])
{
	stak newstak;
	newstak.push(1);
	newstak.push(2);
	newstak.push(3);	
	cout << newstak.top() << "\n";
	newstak.display();
	bool take = newstak.pop();
	cout << newstak.top() << "\n";
	newstak.display();
	return 0;
}
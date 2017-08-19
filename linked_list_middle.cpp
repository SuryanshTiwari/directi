#include "bits/stdc++.h"
using namespace std;

class node{
public:
	int data;
	node *next;
};

int traverse(node *first, int quo){
	int c = 0;
	while(first != NULL){
		c++;
		first = first->next;
		if(c == quo)
			return first->data;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	node *head = new node();
	node *first;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		node *newnode = new node();
		newnode->data = temp;
		newnode->next = NULL;
		if(i == 0){
			first = head;
		}
		head->next = newnode;
		head = head->next;
	}	

	if(n%2 == 0){
		int quo = n/2 + 1;
		cout << traverse(first, quo);
	}else{
		int quo = (n+1)/2;
		cout << traverse(first, quo);
	}	
	return 0;
}
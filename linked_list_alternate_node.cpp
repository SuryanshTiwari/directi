//delete alternate nodes in a linked list

#include "bits/stdc++.h"
using namespace std;

class node{
public:
	int data;
	node *next;
};

int main(int argc, char const *argv[])
{
	node *head = new node();
	node *first = new node();

	first->data = -1;
	head->next = NULL;

	int n;
	cin >> n;

	for(int i = 0; i  < n; i++){
		
		int temp;
		cin >> temp;
		
		node *newnode = new node();

		if(i == 0){
			first = newnode;
		}

		head->next = newnode;
		newnode->data = temp;
		head = newnode;
	}

	int countt = 0;
	node *temp1;
	node *temp = first;
	node *swapp;

	while(first->next != NULL){
		swapp = first->next;
		if(countt % 2  == 0){
			temp1 = first->next->next;
			first->next = temp1;
 		}
 		countt++;
 		first = swapp;
	}

	while(temp != NULL){
		cout << temp->data << "-> ";
		temp = temp->next;
	}
	return 0;
}
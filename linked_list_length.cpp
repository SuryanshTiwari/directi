#include "bits/stdc++.h"
using namespace std;

class node{
public:
	int data;
	node* next;
};

class linkedList:public node{
public:
	int c;
	linkedList(){
		c = 0;
	}
	void recurse(node* head){
		if(head == NULL)return;
		c++;
		recurse(head->next);
	}
	void iterative(node *head){
		while(head != NULL){
			c++;
			head = head->next;
		}
	}
};

int main(int argc, char const *argv[])
{
	node *head = new node();
	node *first = new node();
	node *second = new node();

	head->data = 0;
	head->next = first;
	first->data = 0;
	first->next = second;	
	second->data = 0;
	second->next = NULL;	
	
	linkedList countt;
	cout << countt.c << "\n";
	countt.recurse(head);
	cout << countt.c << "\n";
	// cout << head->data << "\n";
	linkedList countt2;
	cout << countt2.c << "\n";
	countt2.iterative(head);
	cout << countt2.c << "\n";
	return 0;
}
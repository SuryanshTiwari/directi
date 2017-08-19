#include "bits/stdc++.h"
using namespace std;

class node{
public:
	int data;
	node *next;

	node* reverse(node *head){
		node *prev = NULL;
		node *temp;
		while(head != NULL){
			temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}
		return prev;
	}

	void printlist(node *head){
    	while(head != NULL){
        	cout << (head->data) << "->";
        	head = head->next;
    	}
    	cout << "NULL\n";
	}
};


int main(int argc, char const *argv[])
{
	node *head = new node();
	node *first = new node();
	node *second = new node();
	node *third = new node();


	head->data = 0;
	head->next = first;
	first->data = 1;
	first->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;

	head->printlist(head);
	head = head->reverse(head);
	head->printlist(head);

	return 0;
}
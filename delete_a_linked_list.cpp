#include "bits/stdc++.h"
using namespace std;

class node{
public:
	int data;
	node *next;
};

void printlist(node *head){
    // head = head->next;
    while(head != NULL){
        cout << (head->data) << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main(int argc, char const *argv[])
{
	
	node *first = new node();
	node *second = new node();
	node *third = new node();

	
	first->data = 1;
	first->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	
	node *head = first;

	node *temp;
	while(head != NULL){
		temp = head->next;
		delete(head);
		// free(head);
		head = temp;
	}

	printlist(first);
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

class node{
public:	
	int data;
	node *next;
};

void deletenode(node *head,  int val){
	while(head->next != NULL){
		if(head->next->data == val){
			head->next = head->next->next;
			return;
		}	
		head= head->next;
	}
}

void deletenodebyposition(node *head, node *prev, int pos){
	int c = 0;
	while(head != NULL){
		if(c == pos){
			prev->next = head->next;
			return ;
		}
		c++;
		prev = head;
		head = head->next;
	}
}

void printlist(node *head){
    while(head != NULL){
        cout << (head->data) << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

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
	
	int byvalue = 0;

	if(byvalue){
		int dele = 2;
		printlist(head);
		deletenode(head, dele);
		printlist(head);
	}
	else{
		int dele = 1;
		printlist(head);
		deletenodebyposition(head->next, head, dele);
		printlist(head);
	}
	return 0;
}
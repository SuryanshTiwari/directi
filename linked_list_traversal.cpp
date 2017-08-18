#include "bits/stdc++.h"
using namespace std;

class node{
public:
    int data;
    node* next;
};

void printlist(node *head){
    while(head != NULL){
        cout << (head->data) << "->";
        head = head->next;
    }
    cout << "NULL";
}

int main(int argc, char const *argv[])
{
    node *head = new node();
    node *second = new node();
    node *third = new node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printlist(head);
    return 0;
}
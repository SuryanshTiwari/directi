#include "bits/stdc++.h"
using namespace std;

class node{
public:
    int data;
    node *next;
};

void printlist(node *head){
    head = head->next;
    while(head != NULL){
        cout << (head->data) << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n+1];
    
    node *head = new node();
    
    head->data = 0;
    head->next = NULL;
    
    node *first = new node();
    node *second = new node();

    first->data = 0;
    first->next = NULL;

    for(int i = 0; i < n; i++){
        node *newnode = new node();
        cin >> a[i];
        newnode->data = a[i];
        newnode->next = NULL;
        if(i == 0){
            first->next = head;
            second->next = head;
        }
        head->next = newnode;
        head = head->next;
    }

    printlist(second);
    int x, y;
    cin >> x >> y;

    node *swap1 = new node();
    node *prev = new node();
    node *after, *after1, *temp;

    node *prev1 ;

    while(first != NULL){
        if(first->data == x || first->data == y){
            prev1 = first;
            after = first;
            first = first->next;
            break;
        }
        prev = first;
        first = first->next;
    }

    

    while(first != NULL){
        if(first->data == x || first->data == y){
            after1 = first;
            break;
        }
        prev1 = first;
        first = first->next;
    }

    temp = prev->next;
    prev->next = prev1->next;
    prev1->next = temp;

    temp = after->next;
    after->next = after1->next;
    after1->next = temp;
    printlist(second);
    return 0;
}
#include "bits/stdc++.h"
using namespace std;

class node{
public:
    int data;
    node *next;
};

void insertAtBeginning(node* head, int val){
    node *newnode = new node();
    newnode->data = val;
    newnode->next = head->next;
    head->next = newnode;
}

void insertAtend(node* head, int val){
    while(head->next != NULL)
        head = head->next;
    node *newnode = new node();
    newnode->data = val;
    head->next = newnode;
    newnode->next = NULL;
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
    
    head->data = 0;
    head->next = NULL;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int a[2*n+1];
        for(int i = 0; i < 2*n; i++)
            cin >> a[i];
        
        for(int i = 0; i < 2*n; i+=2){
            if(a[i+1] == 0)
                insertAtBeginning(head, a[i]);
            else
                insertAtend(head, a[i]);
            printlist(head);
        }
        
    }
    return 0;
}
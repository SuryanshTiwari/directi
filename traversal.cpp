#include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

struct node* newnode(int data){
    node* node = (struct node*)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void printInorder(node *node){
    
    if(node == NULL)
        return ;
 
    printInorder(node->left);
    cout << (node->data);
    printInorder(node->right);

}

void printPreorder(node *node){
    if(node == NULL)
        return;
    cout << (node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(node *node){
    if(node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << (node->data);
}

int main(int argc, char const *argv[])
{
    node *root = newnode(1);

    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    printInorder(root);
    cout << " ";
    printPreorder(root);
    cout << " ";
    printPostorder(root);
    return 0;
}
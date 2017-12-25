#include "bits/stdc++.h"
using namespace std;

class node{
public:
    int data;
    node *left, *right;
    node(int x){
        data = x;
        left = right = NULL;
    }
};

node* findlca(node* root, int fir, int sec){
    if(root == NULL)
        return NULL;
    if(root->data == fir || root->data == sec)
        return root;
    node* left = findlca(root->left, fir, sec);
    node* right = findlca(root->right, fir, sec);
    if(left != NULL && right != NULL)
        return root;
    if(left != NULL)
        return left;
    else 
        return right;
}

int main(int argc, char const *argv[])
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    node *lca = findlca(root, 6, 7);
    if (lca != NULL)
       cout << "LCA(4, 5) = " << lca->data;
    else
       cout << "Keys are not present ";
    return 0;
}
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

int findd(node* root, int &res){
    if(root == NULL)return 0;
    if(root->left == NULL && root->right == NULL)return root->data;
    int l = findd(root->left, res);
    int r = findd(root->right, res);

    if(root->left != NULL && root->right != NULL){
        res = max(res, l + r + root->data);
        return max(l, r)+root->data;
    }

    if(root->left != NULL){
        return l+root->data;
    }
    if(root->right != NULL){
        return r+root->data;
    }
}

int res;
void finddmax(node *root){
    res = INT_MIN;
    findd(root, res);
}

int main(int argc, char const *argv[])
{
    node *root = new node(-15);
    root->left = new node(5);
    root->right = new node(6);
    root->left->left = new node(-8);
    root->left->right = new node(1);
    root->left->left->left = new node(2);
    root->left->left->right = new node(6);
    root->right->left = new node(3);
    root->right->right = new node(9);
    root->right->right->right= new node(0);
    root->right->right->right->left= new node(4);
    root->right->right->right->right= new node(-1);
    root->right->right->right->right->left= new node(10);

    finddmax(root);
    cout << res;
    return 0;
}
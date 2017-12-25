#include "bits/stdc++.h"
using namespace std;
int res;
class node{
public:
    int data;
    node *left, *right;
    node(int x){
        data = x;
        left = right = NULL;
    }
};

int findd(int &res, node* root){
    if(root == NULL)return 0;

    int l = findd(res, root->left);
    int r = findd(res, root->right);

    res = max(res, root->data + l + r);
    int max_single = max(max(l, r)+root->data, root->data);
    res = max(res, max_single);
    return max_single;
}

void findMaxSum(node* root){
    
    res = INT_MIN;
    findd(res, root);
}

int main(int argc, char const *argv[])
{   
    node *root = new node(10);
    root->left = new node(2);
    root->right = new node(10);
    root->left->left = new node(20);
    root->left->right = new node(1);
    root->right->right = new node(-25);
    root->right->right->left   = new node(3);
    root->right->right->right  = new node(4);
    findMaxSum(root);
    cout << res;    
    return 0;
}
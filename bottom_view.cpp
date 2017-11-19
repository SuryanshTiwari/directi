#include "bits/stdc++.h"
using namespace std;

vector<int> v[10000];

class node{
public:
  int data;
  node *left, *right;
  node(int val){
    data = val;
    left = right = NULL;
  } 
};

// void dfs(node *root, int val){
//   v[val+1000].push_back(root->data);
//   if(root->left != NULL)
//     dfs(root->left, val-1);
//   if(root->right != NULL)
//     dfs(root->right, val+1);
// }

int main(int argc, char const *argv[])
{
  
  node *root = new node(20);
  root->left = new node(8);
  root->right = new node(22);
  root->left->left = new node(5);
  root->left->right = new node(3);
  root->right->left = new node(4);
  root->right->right = new node(25);
  root->left->right->left = new node(10);
  root->left->right->right = new node(14);

  queue<pair<int, node* > > q;

  q.push(make_pair(0, root));
  while(!q.empty()){
    pair<int, node* > topp = q.front();
    v[topp.first+1000].push_back(topp.second->data);
    q.pop();
    if(topp.second->left != NULL){
      q.push(make_pair(topp.first-1, topp.second->left));
    }
    if(topp.second->right != NULL){
      q.push(make_pair(topp.first+1, topp.second->right));
    }
  }

  for(int i = -1000; i <= 1000; i++){
    if(v[i+1000].size() != 0){
        int len = v[i+1000].size()-1;
          cout << v[i+1000][len] << " ";
    }
  }
  return 0;
}
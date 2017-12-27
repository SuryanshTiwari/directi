#include "bits/stdc++.h"
using namespace std;

class node{
public:
	int data;
	node *left, *right;
	node(int val){
		data = val;
		left = right = NULL;
	}
};

int finddmax(node *root, int &res){

	if(root == NULL)return 0;
	if(!root->left && !root->right)return root->data;

	int l, r;
	if(root->left && root->right){
		l = finddmax(root->left, res);
		 r = finddmax(root->right, res);
		res = max(res, l+r+root->data);
		int max_single =  max(l,r)+root->data;
		// res = (max_single, res);
		return max_single;
	}

	if(!root->left){return r+root->data;}if(!root->right){return l+root->data;}
}

int findd(node *root){

	int res = INT_MIN;
	int ress = finddmax(root, res);
	return res;
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	while(t--){
		
		int n;
		cin >> n;
		
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		node *root = new node(a[0]);
		queue<node*> q;
		q.push(root);
		int idx = 0;
		while(idx < n){
			int l = 2*idx+1;
			int r = 2*idx+2;

			node *cur = q.front();
			q.pop();

			if(l < n){
			cur->left = new node(a[l]);
			q.push(cur->left);}
			if(r < n){
			cur->right = new node(a[r]);
			q.push(cur->right);}
			idx++;
		}

		cout << findd(root);

	}
	return 0;
}
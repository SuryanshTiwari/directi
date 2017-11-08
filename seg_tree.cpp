#include "bits/stdc++.h"
using namespace std;
int tree[100000];
int arr[10000];
void build(int st, int en, int node){
  if(st == en){
    tree[node] = arr[st];
    return ;
  }

  if(st > en)
    return;

  int mid = (st+en)/2;
  build(st, mid, node*2);
  build(mid+1, en, node*2+1);
  tree[node] = max(tree[node*2], tree[node*2+1]);
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> arr[i];
  build(0, n-1, 1);
  cout << tree[1];
  return 0;
}
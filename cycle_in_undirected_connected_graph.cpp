#include "bits/stdc++.h"
using namespace std;

vector<int> v[100+1];
bool flag = false;
bool visited[1000];

void iscycle(int st, int par){
    visited[st] = 1;
    for(int i = 0; i < v[st].size(); i++){
      if(v[st][i] != par){
        if(visited[v[st][i]]){
          flag = true;
          continue;
        }
        iscycle(v[st][i], st);
      }
    }
    return ;
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  iscycle(1, -1);
  cout << flag << "\n";
  return 0;
}
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > v[n+1];
    for(int i = 0; i < m; i++){
    
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }

    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> d(n+1, INT_MAX);
    q.push(make_pair(0, 1)); 
    // int d[n+1];
    // memset(d, 0, sizeof d);
    d[1] = 0;
    while(!q.empty()){
        pair<int, int> top = q.top();
        q.pop();
        for(int i = 0; i < v[top.second].size(); i++){
            if(d[v[top.second][i].first] > d[top.second] + v[top.second][i].second){
                d[v[top.second][i].first] = d[top.second] + v[top.second][i].second;
                q.push(make_pair(d[v[top.second][i].first], v[top.second][i].first));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << d[i] << " "; 
    }
    return 0;
}
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

    priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > q;

    vector<int> key(n+1, INT_MAX);
    int visited[n+1];
    memset(visited, 0, sizeof visited);
    q.push(make_pair(0, 1));
    while(!q.empty()){
        pair<int, int> top = q.top();
        q.pop();
        visited[top.second] = 1;
        for(int i = 0; i < v[top.second].size(); i++){
            if(visited[v[top.second][i].first] == 0 && key[v[top.second][i].first] > v[top.second][i].second){
                key[v[top.second][i].first] = v[top.second][i].second;
                q.push(make_pair(key[v[top.second][i].first], v[top.second][i].first));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << key[i] << " ";
    }   
    return 0;
}
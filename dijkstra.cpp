#include "bits/stdc++.h"
using namespace std;
#define  pii pair<int, int>
bool visited[10000];
int dist[10000];
int main(int argc, char const *argv[])
{
    priority_queue<pii, vector<pii> , greater<pii> >  q;
    int V = 9;
    int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    
    for(int i = 1; i < 1000; i++)dist[i] = INT_MAX;

    q.push(make_pair(0, 0));
    while(!q.empty()){
        pii temp = q.top();
        q.pop();
        int node = temp.second;//cout << node << " ";
        for(int i = 0; i < V; i++){
            if(graph[node][i] != 0){
                if(dist[i] > dist[node] + graph[node][i]){
                    dist[i] = dist[node] + graph[node][i];
                    q.push(make_pair(dist[i],i));
                }
            }
        }
    }

    for(int i = 0; i < V; i++)
        cout << dist[i] << " ";
    return 0;
}
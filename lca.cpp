
// https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/#Lowest%20Common%20Ancestor%20(LCA)
#include "bits/stdc++.h"
using namespace std;
 
vector<int> v[1010];
int T[1010]; //for storing father of nodes in the tree
int L[1010]; //storing level of node
int nr;
int visited[1011];
int visited1[1011];
int P[1010];
 
 
void dfs(int node)
{
    visited1[node] = 1;
 
    if(L[node] < nr)
    {
        P[node] = 1;
    }
    else
    {
        if(!(L[node] % nr))
        {
            P[node] = T[node];
        }
        else
        {
            P[node] = P[T[node]];
        }
    }
 
    for(int i = 0; i < v[node].size(); i++)
    {
        if(visited1[v[node][i]] == 0)
            dfs(v[node][i]);    
    }
}
 
int LCA(int x, int y)
{
    while(P[x] != P[y])
    {
        if(L[x] > L[y])
        {
            x = P[x];
        }
        else
        {
            y = P[y];
        }
    }
 
    while(x != y)
    {
        if(L[x] > L[y])
        {
            x = T[x];           
        }
        else
            y = T[y];
    }
    return x;
}
 
void bfs()
{
    queue<int> q;
    q.push(1);
    
    T[1] = 1;
    L[1] = 0;
 
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
 
        visited[top] = 1;
        
        for(int i = 0; i < v[top].size(); i++)
        {
            if(visited[v[top][i]] == 0)
            {
                q.push(v[top][i]);
                T[v[top][i]] = top;
                L[v[top][i]] = L[top] + 1;
            }
        }
    }
}
 
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    
    int c = 1;
    
    while(t--)
    {
        cout << "Case " << c << ":\n";
        c++;
        
        for(int i = 0; i < 1010; i++)
        {
            T[i] = L[i] = P[i] = visited[i] = visited1[i] = 0;  
            v[i].clear();
        }
 
        int n;
        cin >> n;
 
        for(int j = 1; j <= n; j++)
        {
            int h;
            cin >> h;
 
            for(int i = 0; i < h; i++)
            {
                int x;
                cin >> x;
 
                v[j].push_back(x);
                v[x].push_back(j);
            }
        }
        bfs();
        
        vector<int> v1;
        for(int i = 1; i <= n; i++)
        {
            // cout << L[i] << " ";
            v1.push_back(L[i]);
        }
 
        sort(v1.begin(), v1.end());
 
        int max1 = *max_element(v1.begin(), v1.end());
        int min1 = *min_element(v1.begin(), v1.end());
        nr = sqrt(max1 - min1);
        if(nr == 0)nr = 1;
        // cout << max1 << " " << min1;
        dfs(1);
 
        int q;
        cin >> q;
 
        while(q--)
        {
            int v1, w;
            cin >> v1 >> w;
 
            cout << LCA(v1, w) << "\n";
        }
    }
    return 0;
} 

//O(sqrt(n))complexity

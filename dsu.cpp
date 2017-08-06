include "bits/stdc++.h"
using namespace std;
#define ll long long
ll root (ll Arr[ ] ,ll i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ; 
i = Arr[ i ]; 
    }
return i;
}
void weightedunion(ll Arr[ ],ll size[ ],ll A,ll B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(root_A == root_B)return;
    if(size[root_A] < size[root_B ])
    {
Arr[ root_A ] = Arr[root_B];
size[root_B] += size[root_A];
}
    else
    {
Arr[ root_B ] = Arr[root_A];
size[root_A] += size[root_B];
}
 
}
void initialize( ll Arr[ ], ll size[], ll N)
{
    for(int i = 1;i<=N;i++)
    {
Arr[ i ] = i ;
size[ i ] = 1;
}
}
int main()
{
ll n, m, x;
cin >> n >> m >> x;
int a[n+1];
ll arr[n+1];
ll size[n+1];
// memset(a, 0, sizeof a);
ll kk[n+1];
// memset(kk,0, sizeof kk);
ll visited[n+1];
// memset(visited, 0, sizeof visited);
for(int i = 0; i <= n; i++)visited[i] = kk[i] = a[i] = 0;
for(int i = 0; i < m; i++)
{
ll xxx;
cin >> xxx;
a[xxx] = 1;
}
 
initialize(arr, size, n);
 
for(int i = 0; i < x; i++)
{
ll g, h;
cin >> g >> h;
weightedunion(arr, size, g, h);
}
memset(visited, 0, sizeof visited);
long long sum = 0;
for(int i = 1; i <= n; i++)
{
    if(a[i] == 1)
    {
       ll roott = root(arr, i);
       kk[roott] += 1;
    }
}
for(int i = 1; i <= n; i++)
{
    ll roott = root(arr, i);
    if(visited[roott] == 0)
    {
  //      cout << kk[roott] << " " ;
        visited[roott] = 1;
        sum += size[roott]*kk[roott];
    }
}
cout << sum << "\n";
return 0;
}
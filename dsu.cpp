

#include<bits/stdc++.h>
using namespace std;


int sz[1000005],parent[1000004],arr[1000005] ;
int N , M ;
int root(int a)
{
    while(a!=parent[a]) {
        a = parent[a] ;
    }
    return a ;
}
void join(int a,int b)
{
    a = root(a) , b = root(b) ;
    if(sz[a] > sz[b]) {
        parent[b] = a ;
        sz[a] += sz[b] ;
    }
    else {
        parent[a] = b ;
        sz[b] += sz[a] ;
    }
    return ;
}
vector<int> haha[1000005] ;
int main()
{
    scanf("%d%d",&N,&M) ;
    rep(i,1,N) {
        scanf("%d",&arr[i]) ;
        sz[i] = 1 ;
        parent[i] = i ;
    }
    rep(i,1,M) {
        int u , v ;
        scanf("%d%d",&u,&v) ;
        join(u,v) ;
    }
    rep(i,1,N) {
        haha[root(i)].push_back(arr[i]) ;
    }
    rep(i,1,N) {
        sort(all(haha[i])) ;
    }
    rep(i,1,N) {
        printf("%d ",haha[root(i)].back()) ;
        haha[root(i)].pop_back() ;
    }
    return 0;
}
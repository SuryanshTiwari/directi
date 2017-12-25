#include "bits/stdc++.h"
using namespace std;

int parent[n+1];
int size[n+1];

int par(int a){
    while(a != parent[a]){
        a = parent[a];
    }
    return a;
}

void join(int a, int b){
    a = par(a);
    b = par(b);
    if(size[a] > size[b]){
        size[a] += size[b];
        parent[b] = a;
    } else{
        size[b] += size[a];
        parent[a] = b;
    }
}
int main(int argc, char const *argv[])
{
    
    for(int i = 0; i < n; i++){
        parent[i] = i;
        size[i] = 1;
    }   
    return 0;
}
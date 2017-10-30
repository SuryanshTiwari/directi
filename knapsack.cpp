#include "bits/stdc++.h"
using namespace std;
int wt[100000], val[100000];
int dp[1000][1000];

int recurse(int st, int W, int n){
    // cout << W << "\n";
    if(W < 0)return -1000000000;
    if(st == n)return 0;
    if(W == 0)return 0;
    
    if(dp[st][W] != -1)return dp[st][W];
    // if (wt[st] > W)
       // return recurse(st+1, W, n);
    int temp = max(recurse(st+1, W-wt[st], n)+val[st], recurse(st+1, W, n));
    return dp[st][W] = temp;
}

int main(int argc, char const *argv[])
{
    int n, W;
    cin >> n >> W;

    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++)
            dp[i][j] = -1;
    }

    for(int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    cout << recurse(0, W, n);
    return 0;
}
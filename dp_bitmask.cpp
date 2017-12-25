#include "bits/stdc++.h"
using namespace std;
int dp[10000][100];
int ss(int mask, int prev, int n){
    if(dp[mask][prev] != -1)
        return dp[mask][prev];
    for(int i = 0; i < n; i++){
        if(mask & (1<<i) == 1)continue;
        dp[mask][prev] = max(dp[mask][prev], ss(mask|(1<<i), i, n) + __gcd(a[i], a[prev]));
    }
    return dp[mask][prev];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int a[n+1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < 100; j++){
            dp[i][j] = -1;
        }
    }
    int mask = 0;
    int max1 = 0;
    for(int i = 0; i < n; i++){
        max1 = max(max1, ss(mask|(1<<i), i, n));
    }
    cout << max1;
    return 0;
}
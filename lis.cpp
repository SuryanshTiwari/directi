#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int a[n];
    int dp[n+1];
    for(int i = 0; i < n; i++){
        cin >> a[i];    
        dp[i] = 1;
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(a[i] < a[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int max1 = 0;
    for(int i = 0; i < n; i++){
        max1 = max(max1, dp[i]);
    }

    cout << max1 ;
    return 0;
}


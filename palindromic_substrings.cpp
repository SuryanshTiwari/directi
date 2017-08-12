#include "bits/stdc++.h"
using namespace std;

int dp[1001][1001];
int P[1001][1001];
int recurse(string s, int st, int en){

    if(st >= en)
        return 0;
    if(dp[st][en] != -1)return dp[st][en];
    int ways;

    
    ways = recurse(s, st+1, en) + recurse(s, st, en-1) - recurse(s, st+1, en-1);
    
    if(s[st] == s[en] && P[st+1][en-1]){
        P[st][en] = 1;
    }
    if(s[st] == s[en] && (en-st) == 1){
        P[st][en] = 1;
    }
    if(P[st][en]){
        ways += 1;
    }

    return dp[st][en]  = ways;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    
    while(t--){
        int n;cin >> n;
        string s;
        cin >> s;
    
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++){
                if(i == j){
                    dp[i][j] = 0;
                    P[i][j] = 1;
                }
                else{
                    dp[i][j] = -1;P[i][j] = 0;}
            }
        }
    
        cout << recurse(s, 0, s.length()-1) << "\n";
    }
    return 0;
}
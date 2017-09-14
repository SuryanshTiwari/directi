#include "bits/stdc++.h"
using namespace std;
string s;
int dp[101][101];
int max1 = 0;
int st, en;
int recurse(int st, int en){

    if(st > en){
        return 1;
    }
    if(st == en){
        return 1;
    }
    if(dp[st][en] != -1){
        return dp[st][en];
    }
    dp[st][en] = (recurse(st+1, en-1) & (s[st]==s[en]));
    if(st+1 < s.length())
        dp[st+1][en] = recurse(st+1, en) & (s[st+1]==s[en]);
    if(en-1 >= 0)
        dp[st][en-1] = recurse(st, en-1) & (s[st]==s[en-1]);
    return dp[st][en];
    // if(dp[st][en] == 0){
    // }
    // if(dp[st+1][en] == 0){
    // }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--){
        cin >> s;
        
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++)
                dp[i][j] = -1;
        }

        int ans = recurse(0, s.length()-1);

        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++){
                if(dp[i][j]){
                    if(max1 < (j-i+1)){
                        max1 = j-i+1;
                        st = i;
                        en = j;
                    }
                }
            }   
        }

        cout << s.substr(st, en-st+1) << "\n";
    }
    return 0;
}
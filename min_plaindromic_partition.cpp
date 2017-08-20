#include "bits/stdc++.h"
using namespace std;
int dp[101][101];
int recurse(string A, int st, int en){
    // if(st > en)return -1;
    if(st == en)return 0;
    if(dp[st][en] != -1)return dp[st][en];
    int min1 = INT_MAX;
    string s = A.substr(st, en-st+1);
    string temp = s;
    reverse(s.begin(), s.end());
    if(s == temp){
        return 0;
    }
    for(int i = st; i <= en; i++){
    	if(i+1 <= en)
        	min1 = min(min1, recurse(A, st, i) + recurse(A, i+1, en) + 1);
    }
    return dp[st][en] = min1;
}


int main(int argc, char const *argv[])
{
	string A = "ababbbabbababaabababbabababbababababababababababbabababbbbbbaaaaabaabba";
   for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
            dp[i][j] = -1;
    cout << recurse(A, 0, A.length()-1);
    return 0;
}	
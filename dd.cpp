#include "bits/stdc++.h"
using namespace std;
int c[3][3] = { 
		{0,1,2},
		{1,2,1},
		{2,1,2}
	};
int p[3][3] = { 
		{0,2,3},
		{1,0,1},
		{0,0,1}
	};
int dp[1001][1001][2];
int recurse(int n, int m, int i, int j, int idx){

	if(dp[i][j][idx] != INT_MAX)return dp[i][j][idx];
	if(i == n-1 && j == m-1)return 0;
	if(idx == 0){
		if(i+1 < n)
			dp[i][j][idx] = recurse(n, m, i+1, j, idx^1)+p[i][j]+c[i+1][j];
		if(j+1 < m)
			dp[i][j][idx] = min(dp[i][j][idx], recurse(n, m, i, j+1, idx)+c[i][j+1]);
	}else{
		if(i+1 < n)
			dp[i][j][idx] = recurse(n, m, i+1, j, idx)+c[i+1][j];
		if(j+1 < m)
			dp[i][j][idx] = min(dp[i][j][idx], recurse(n, m, i, j+1, idx^1)+p[i][j]+c[i][j+1]);		
	}
	return dp[i][j][idx];
}
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < 1001; i++){
		for(int j = 0; j < 1001; j++)
			dp[i][j][0] = dp[i][j][1] = INT_MAX;
	}
	
	cout << min(recurse(n, m, 0, 0, 0), recurse(n, m, 0, 0, 1));
	return 0;
}
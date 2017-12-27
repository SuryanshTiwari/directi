#include "bits/stdc++.h"
using namespace std;
int a[] = {1, 2, 3, 6, 1, 4};
int b[] = {4, 5, 1};
int dp[100][100];
int recurse(int idx, int idx2, int c, int n, int m){
	if(idx == n)return 0;
	if(idx2 == m)return 0;
	if(dp[idx][idx2] != -1)
		return dp[idx][idx2];
	int max1 = 0;
	max1 = recurse(idx+1, idx2+1, c, n, m) + a[idx]*b[idx2];
	if(c < (n-m))
		max1 = max(max1, recurse(idx+1, idx2, c+1, n, m));
	return dp[idx][idx2] = max1;
}

int main(int argc, char const *argv[])
{
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++)
			dp[i][j] = -1;
	}
	cout << recurse(0 ,0, 0, 6, 3);
	return 0;
}
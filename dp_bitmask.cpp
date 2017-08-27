//problem link = https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/shil-and-new-year-gift/description/
#include "bits/stdc++.h"
using namespace std;
int dp[(1<<15)][15];
int n;
int a[15];
int recurse(int mask, int prev){
	if(mask == ((1<<n)-1))return 0;
	if(dp[mask][prev] != -1)return dp[mask][prev];
	for(int i = 0; i < n; i++){
		if(mask&(1<<i))continue;
		dp[mask][prev] = max(dp[mask][prev], recurse(mask|(1<<i), i)+__gcd(a[i],a[prev]));
	}
	return dp[mask][prev];
}

int main(int argc, char const *argv[])
{
	
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0 ; i < (1<<n); i++)
		for(int j =  0; j < n; j++)
			dp[i][j] = -1;
		
	int mask = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, recurse(mask|(1<<i), i));
	}
	cout << ans;
	return 0;
}
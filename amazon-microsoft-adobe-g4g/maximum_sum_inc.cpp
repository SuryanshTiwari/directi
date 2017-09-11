#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;


	while(t--){
		int n;
		cin >> n;

		int a[n+1];
		int dp[n+1];
		int max1 = -1;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			dp[i] = a[i];
			max1 = max(max1, dp[i]);
		}


		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(a[j] > a[i]){
					dp[j] = max(dp[j], a[j] + dp[i]);
				}
			}
		}


		
		for(int i = 0; i < n; i++)
			max1 = max(max1, dp[i]);

		cout << max1 << "\n";
	}
	return 0;
}
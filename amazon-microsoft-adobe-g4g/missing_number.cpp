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
		for(int i = 0; i < n-1; i++)
			cin >> a[i];

		int hash[n+1];
		memset(hash, 0, sizeof hash);

		for(int i = 0; i < n-1; i++){
			hash[a[i]]++;
		}

		for(int i = 1; i <= n; i++){
			if(hash[i] == 0){
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}
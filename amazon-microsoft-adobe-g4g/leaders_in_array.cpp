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
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		int suff_max[n+1];
		for(int i = n-1; i >= 0; i--){
			if(i < n-1)
				suff_max[i] = max(a[i], suff_max[i+1]);
			else{
				suff_max[i] = a[i];
			}
		}

		vector<int> leaders;
		leaders.push_back(a[n-1]);
		for(int i = n-2; i >= 0; i--){
			if(suff_max[i+1] < a[i]){
				leaders.push_back(a[i]);
			}
		}
        sort(leaders.begin(), leaders.end());
        reverse(leaders.begin(), leaders.end());
		for(int i = 0; i < leaders.size(); i++){
			cout << leaders[i] << " "; 
		}
		cout << "\n";

	}
	return 0;
}
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
		for(int i = 0; i < n; i++)
			cin >> a[i];

		int max1 = 0;
		int curr_sum = 0;
		int global_sum = 0;

		max1 = 0;

		while(it+1 < n){
			it = it+1;
			if(a[max1] <= a[it]){
				global_sum += (it-max1)*a[max1];
				max1 = it;
			}
		}
	}
	return 0;
}
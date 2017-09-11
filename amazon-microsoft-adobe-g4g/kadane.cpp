//link = http://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
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

		int max_till_here = 0, uni_max = -INT_MAX;

		for(int i = 0; i < n; i++){
			if(a[i] >= 0){
				max_till_here += a[i];
				uni_max = max(uni_max, max_till_here);
			}else if(a[i] < 0){
				if(max_till_here + a[i] < 0){
				    uni_max = max(uni_max, max_till_here+a[i]);
					max_till_here = 0;
				}
				else{
					max_till_here += a[i];
					uni_max = max(uni_max, max_till_here);
				}
			}
		}
        
		cout << uni_max << "\n";
	}

	return 0;
}
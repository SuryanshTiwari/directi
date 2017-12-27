
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n, b;
	cin >> n >> b;
	
	int a[n+1];
	int max1 = 0;
	for(int i = 0;  i < n; i++){
		cin >> a[i];
		max1 = max(max1, a[i]);
	}

	int lo = 1;
	int hi = max1;

	int ans = 0;
	while(lo <= hi){

		int mid = lo + (hi-lo)/2;
		cout << mid << " ";
		int cake = b;
		int c = 0;int req= 0;
		for(int i = 0; i < n; i++, c++){
			// if(cake <= 0){break;}
			// if(mid > a[i]){flag = 0;break;}
			if(mid > a[i]){
				req+=1;
				continue;
			}
			req+= ceil((double)a[i]/mid);
			// cake -= req;
		}
		// if(flag == 0){
		// 	hi = mid-1;
		// 	// cout << hi << "\n";
		// 	continue;
		// }
		if( req <= b){
			// lo = mid+1;
			hi = mid-1;
			ans = mid;
		}else{
			// hi = mid-1;
			lo = mid+1;
		}
	}

	cout << ans;
	return 0;
}	
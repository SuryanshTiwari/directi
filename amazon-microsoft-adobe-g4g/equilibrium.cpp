#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;


	while(t--){

		int n;
		cin >> n;
		
		int cumu[n+1];

		int a[n+1];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(i == 0)
				cumu[i] = a[i];
			else{
				cumu[i] = a[i] + cumu[i-1];
			}
		}
		if(n == 1){
            cout << 1 << "\n";
            continue;
        }
		int equ = -1;
		for(int i = 1; i < n; i++){
			int right = cumu[n-1] - cumu[i];
			int left = cumu[i-1];
			if(left == right){
				equ = i;
			}
		}

		if(equ == -1){
			cout << "-1" << "\n";
		}else{
			cout << equ+1 << "\n";
		}

	}
	return 0;
}
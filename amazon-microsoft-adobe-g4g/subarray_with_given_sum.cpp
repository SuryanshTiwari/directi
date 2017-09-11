#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	while(t--){
		int n, k;
		cin >> n >> k;

		int a[n+1];
		for(int i = 1; i <= n; i++)
			cin >> a[i];

		int pref[n+1];
		memset(pref, 0, sizeof pref);

		vector<int> sort_pref;

		for(int i = 1; i <= n; i++){
			if(i == 1){
				pref[i] = a[i];
			}else{
				pref[i] = pref[i-1] + a[i];
			}
			sort_pref.push_back(pref[i]);
		}
		int st=-1, en=-1;
		for(int i = 1; i <= n; i++){
			int findd = pref[i-1] + k;
			if(binary_search(sort_pref.begin(), sort_pref.end(), findd)){
				st = i-1;
				for(int i = st+1; i <= n; i++){
					if(pref[i] == findd){
						en = i;
						break;
					}
				}
				if(en != -1)
				    break;
			}
		}

		if(st == -1 || en == -1){
			cout << "-1\n";
		}else{
			cout << st+1 << " " << en << "\n";
		}
	}
	return 0;
}
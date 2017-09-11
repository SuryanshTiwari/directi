#include "bits/stdc++.h"
using namespace  std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	while(t--){

		
		int k;
		cin >> k;
		int n;
		cin >> n;
		int a[n+1];
		multiset<int> q;

		for(int i = 0; i < n; i++){
			cin >> a[i];
			q.insert(a[i]);
			if(i < k-1){
				cout << -1 << " ";
			}else if(i > k-1){
				q.erase(*q.begin());
				cout << *q.begin() << " ";
			}else{
				cout << *q.begin() << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
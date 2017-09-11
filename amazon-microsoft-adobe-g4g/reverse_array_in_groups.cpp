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

		int k;
		cin >> k;

		vector<pair<int, int> > v;
		for(int i = 0; i < n; i+=k){
			if(i+k-1 < n)
				v.push_back(make_pair(i+k-1, i));
			else{
				v.push_back(make_pair(n-1, i));
			}
		}

		for(int i = 0; i < v.size(); i++){
			for(int j = v[i].first; j >= v[i].second; j--){
				cout << a[j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
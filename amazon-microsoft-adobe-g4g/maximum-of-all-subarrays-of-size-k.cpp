#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	while(t--){

		int n;
		cin >> n;

		multiset<int> q;
		int a[n+1];
		int k;
		cin >> k;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		

		for(int i = 0; i < k; i++)
			q.insert(a[i]);
		// cout << q.top() << " ";
		cout << *q.rbegin() << " ";
		int prev = 0;
		int next = k-1;
		while(next+1 < n){
			next = next+1;
			multiset<int>::iterator it;
			it = q.find(a[prev]);
			q.erase(it);
			q.insert(a[next]);
			prev += 1;
			cout << *q.rbegin() << " ";
		}
		cout << "\n";

	}
	return 0;
}
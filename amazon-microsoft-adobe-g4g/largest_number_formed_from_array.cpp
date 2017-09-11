//this solution is wrong, its not even a solution its just shit
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		string a[n+1];
		for(int i = 0; i < n; i++)
			cin >> a[i];

		for(int i = 0; i <= n-1; i++){
			for(int j = 0; j+1 <= n-i-1; j++){
				if(a[j] > a[j+1])swap(a[j],a[j+1]);
			}
		}

		reverse(a, a+n);
		
		string temp = "";
		for(int i = 0; i < n; i++)
			temp += a[i];

		cout << temp << "\n";

	}
	return 0;
}
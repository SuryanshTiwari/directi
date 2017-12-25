#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int a[] = {};

	stack<int> s;
	int i = 0;

	while(i < n){

		if(s.empty() || a[s.top()] <= a[i]){
			s.push(i++);
		}else{
			int tp = s.top();
			s.pop();

			int val = a[tp]* (s.empty()?i:i-s.top()-1);
			max1 = max(max1, val);
		}
	}
	return 0;
}
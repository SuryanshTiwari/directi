#include "bits/stdc++.h"
using namespace std;

void update(int idx, int val){
	while(idx <= n){
		tree[idx] += val;
		idx += (idx & (-idx));
	}
}

int read(int idx){
	int sum = 0;
	while(idx > 0){
		sum += tree[idx];
		idx -= (idx & (-idx));
	}
	return sum;
}
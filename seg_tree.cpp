#include "bits/stdc++.h"
using namespace std;

void build(int node, int l, int r){
	if(l == r)
		return tree[node] = a[l];

	build(node*2, l, (l+r)/2);
	build(node*2+1, (l+r)/2+1, r);

	tree[node] = max(tree[node*2], tree[node*2+1]);
}
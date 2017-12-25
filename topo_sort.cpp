#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{

	int indegree[n+1];
	memset(indegree, 0, sizeof indegree);

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		indegree[y]++;
	}

	queue<int> q;
	for(int i = 0; i < n; i++){
		if(indegree[i] == 0)
			q.push(i);
	}

	while(!q.empty()){
		int tp = q.top();
		q.pop();
		for(int i = 0; i < v[tp].size(); i++){
			indegree[v[tp][i]]--;
			if(indegree[v[tp][i]] == 0)
				q.push(v[tp][i]);
		}
	}
	return 0;
}
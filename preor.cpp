#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int pre[] = {2, 4, 3};
	
	stack<int> s;
	s.push(pre[0]);
	int root = INT_MIN;
	int flag = 1;
	for(int i = 1; i < sizeof(pre)/sizeof(pre[0]); i++){
		if(pre[i] < root){
			flag = 0;
			break;
		}
		while(!s.empty() && pre[i] > s.top()){
			root = s.top();
			s.pop();
		}
		s.push(pre[i]);
	}
	
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sqrt(i); j++){
			if(i%j == 0){
				divisors[i].push_back(j);
			if(i/j != j)
				divisors[i].push_back(i/j);
			}
		}
    }

	return 0;
}
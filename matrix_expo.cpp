//https://www.hackerearth.com/challenge/college/codemania-20/algorithm/coin-toss/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define MOD 1000000007
#define DIM 2 // default to 2. Set value according to problem.
struct matrix{
  ll a[DIM][DIM];
	
	// constructor. Make an empty array.
	matrix() {
		memset(a, 0, sizeof(ll) * DIM * DIM);
	}
	
	// constant matrix (M). Set value according to problem.
	void unit_matrix() {
		a[0][0] = 3; a[0][1] = 1;
		a[1][0] = -1; a[1][1] = 0;
	}
	
	matrix operator* (matrix b) {
		matrix c;
		for (int k = 0; k < DIM; ++ k) { 
			for (int i = 0; i < DIM; ++i) {
				for (int j = 0; j < DIM; ++j) {
					c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
				}
			}
		}
		return c;
	}
};
 
matrix pow_matrix(matrix a, ll n) {
	if (n == 1) return a;
	
	matrix b = pow_matrix(a, n / 2);
	b = b * b;
	if (n & 1) b = b * a;
	
	return b;
}

ll pwr(ll val, ll n){
	if(n == 0)return 1;
	if(n == 1)return val;
	ll ans = pwr(2, n/2);
	ans = (ans*ans)%MOD;
	if(n & 1)ans = (ans * val)%MOD;
	return ans;
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;
		matrix a;
		// a.matrix();
		a.unit_matrix();
		

		if(n == 1){cout << "2" << "\n";}
		else if(n == 2){cout << "4" << "\n";}
		else if(n == 3){cout << "7" << "\n";}
		else if(n == 4){cout << "13" << "\n";}
		else{
			matrix b = pow_matrix(a, n-4);
			ll val = (3*b.a[0][0] + 1*b.a[1][0])%MOD;
			ll two = pwr(2, n);	
			cout << (two-val+MOD)%MOD << "\n";	
		}
	}
	return 0;
}
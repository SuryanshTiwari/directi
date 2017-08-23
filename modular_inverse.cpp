//(a/b)%m = (a%m * b^(m-2))%m
ll powr(ll a,ll b,ll mod) {a%=mod;if(a<0)a+=mod;ll ans=1; while(b) {if(b&1) ans=(ans*a)%mod; a=(a*a)%mod; b/=2; } return ans; }
ll modularInverse(ll a,ll m) {/*reminder: make sure m is prime*/ return powr(a,m-2,m); }

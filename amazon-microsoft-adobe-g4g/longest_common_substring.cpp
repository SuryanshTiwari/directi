#include "bits/stdc++.h"
using namespace std;
#define ll unsigned long long
#define MOD 1000000007
ll powr(ll a,ll b,ll mod) {a%=mod;if(a<0)a+=mod;ll ans=1; while(b) {if(b&1) ans=(ans*a)%mod; a=(a*a)%mod; b/=2; } return ans; }
ll modularInverse(ll a,ll m) {/*reminder: make sure m is prime*/ return powr(a,m-2,m)%m; }
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--){
        
        int nn, nn1;
        cin >> nn >> nn1;

        string x, y;
        cin >> x >> y;
        
        const ll p = 31;
        vector<ll> v(max(x.length(), y.length()));
        v[0] = 1;
        for(int i = 1; i < v.size(); i++){
            v[i] = (v[i-1]*p)%MOD;
        }
        vector<ll> h(x.length());
        vector<ll> h1(y.length());
        
        for(int i = 0; i < x.length(); i++){
            h[i] = ((x[i] - 'A' + 1) * v[i])%MOD;
            if(i)h[i] = (h[i] + h[i-1])%MOD;
        }

        for(int i = 0; i < y.length(); i++){
            h1[i] = ((y[i] - 'A' + 1) * v[i])%MOD;
            if(i)h1[i] = (h1[i] + h1[i-1])%MOD;
        }
        // cout << ((h[4] - h[1] + MOD)%MOD)/v[2] << "\n";
        // cout << ((h1[3] - h1[0] + MOD)%MOD)/v[1] << "\n";
        int lo = 0;
        int hi = min(x.length(), y.length()) + 1;
        int ans = 0;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            int flag = 0;

            for(int i = 0; i+mid-1 < x.length(); i++){
                ll search ;
                if(i)
                    search = ((h[i+mid-1] - h[i-1] + MOD)%MOD)*modularInverse(v[i], MOD);
                else
                    search = h[i+mid-1];
                search = search%MOD;
                
                for(int j = 0; j+mid-1 < y.length(); j++){
                    ll res;
                    if(j)
                    res = ((h1[j+mid-1] - h1[j-1] + MOD)%MOD)*modularInverse(v[j], MOD);
                else
                    res = h1[j+mid-1];
                res = res%MOD;
                // if(mid == 3){
                //         if(i==2){if(j==1)cout << search << " " << res << "\n";}
                // }
                if(res == search){
                    flag = 1;
                    break;
                }
            }   
            if(flag)break;
        }

        if(flag){
            // cout << mid << "\n";
            ans = max(ans, mid); 
            lo = mid+1;
        }
        else hi = mid-1;
    }

    cout << ans << "\n";
}
    return 0;
}
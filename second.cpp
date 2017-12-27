#include "bits/stdc++.h"
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    // int t;
    // cin >> t;

    // while(t--){
        long long h, n;
        cin >> h >> n;
        long long sum = 0;
        bool way = 0;//left
        long long temp = 1;
        while(h!=0){
        long long lim = (1ll<<h);
        long long sec = lim/2 + temp;
        if(n >= sec && way == 0){
            sum += lim;
            temp = lim/2 + temp;
            // way ^= 1;
        }else if(n >= sec && way == 1){    
            way ^= 1;
            temp = lim/2 + temp;
            sum += 1;
        }else if(n < sec && way == 0){
            way ^= 1;
            // temp = lim/2 + temp;
            sum += 1;
        }else if(n < sec && way == 1){
            // way ^= 1;
            // temp = lim/2 + temp;
            sum += (1ll<<h);
            // cout << h << " " << (1<<h) <<  "\n";
        }

        h = h-1;
    }
    if(n%2==0){
    cout << sum << "\n";
    }else{
        cout << sum << "\n";
    }

    return 0;
}
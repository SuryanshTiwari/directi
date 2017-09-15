#include "bits/stdc++.h"
using namespace std;
int bit[100009];

void update(int idx){
    while(idx < 100009){
        bit[idx] += 1;
        idx += (idx&(-idx));
    }
}

int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= (idx&(-idx));
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;


    for(int i = 1; i <= n; i++){

        int x;
        cin >> x;

        if(i == 1){
            cout << x << "\n";
            update(x);
            continue;
        }
        update(x);
        
        int lo = 0;
        int hi = 100009;
        int ans;
        int len = (i+1)/2;
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            int temp = read(mid);
            if(temp >= len){
                // if(i == 2)
                //     cout << mid << "\n";
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
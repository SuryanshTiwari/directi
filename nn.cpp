#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<int> v[m+1];
        int nott[n+1];
        memset(nott, 0, sizeof nott);

        for(int i = 1; i <= m; i++){
            int l;
            cin >> l;
            for(int k = 0; k < 2*l; k++){
                int x;
                cin >> x;
                v[i].push_back(x);
                if(k == l-1){
                    v[i].push_back(-2);
                }
            }
            
            char ch;
            cin >> ch;
            if(ch == '>'){
                reverse(v[i].begin(), v[i].end());
            }else if(ch == '='){
                for(int k = 0; k < v[i].size(); k++){
                    nott[v[i][k]] = 1;
                }
                v[i][0] = -1;
            }
        }
        
        for(int i = 1; i <= m; i++){

            if(v[i][0] != -1){
                int x = v[i].size()/2;
                memset(freq, 0, sizeof freq);
                memset(freq1, 0, sizeof freq1);
                int freq[n+1];int freq1[n+1];
                for(int j = 0; j < (v[i].size()/2); j++,x++){
                    freq[v[i][j]]++;
                    freq1[v[i][x]]++;
                }
                for(int j = 0; j < (v[i].size()/2); j++){
                    if(freq1[v[i][j]] >= 1)nott[v[i][j]] = 1;
                }
            }
        }

        for(int i = 1; i <= m; i++){
            if(v[i][0] != -1){

            }
        }
    }
    return 0;
}
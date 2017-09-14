#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        stack<char> st;
        st.push(s[0]);

        int flag = -1;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == st.top()){flag = 1;continue;}
            else{
                if(flag == 1){
                    st.pop();
                }
                flag = -1;
                if(st.empty()){st.push(s[i]);continue;}
                if(s[i] == st.top()){flag=1;continue;}
                st.push(s[i]);
            }
        }

        if(flag == 1){
            st.pop();
        }

        vector<char> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }

        for(int i = v.size()-1; i >= 0; i--){
            cout << v[i];
        }
        cout << "\n";
    }
    return 0;
}
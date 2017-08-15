#include "bits/stdc++.h"
using namespace std;


int main(int argc, char const *argv[])
{
    string s = "/a/./../b/c/";
vector<string> tokens;
    stringstream stream(s);
    string tok;
    while(getline(stream, tok, '/')){
        tokens.push_back(tok);
    }

    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << " ";
    

    return 0;
}
#include "bits/stdc++.h"
using namespace std;

int dx[] = {-1, 1, 0, -1, 1, 0, -1, 1};
int dy[] = {-1, 0, 1, 1, -1, -1, 0, 1};

char grid[3][3] = {{'a','b','c'},{'d','e','f'},{'g','h','i'}};
string words[] = {"a","abedhi","efgh"};

int visited[101][101];

int check(string str, pair<int,int> coor, int idx){
    if(idx >= str.size())return 1;
    pair<int,int> temp;
    if(grid[coor.first][coor.second] == str[idx] && visited[coor.first][coor.second] == 0){
        visited[coor.first][coor.second] = 1;
        for(int k = 0; k < 8; k++){
            temp.first = dx[k] + coor.first;
            temp.second = dy[k] + coor.second;
            if(check(str, temp, idx+1))return 1;
        }
    }
    else{
        return 0;
    }
    return 0;
}

int main(){
   
    vector<pair<int,int> > v[27]; 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            v[grid[i][j]-'a'].push_back(make_pair(i,j));
        }
    }  
    for(int i = 0; i < 3; i++){
        string str = words[i];
        for(int j = 0; j < v[str[0]-'a'].size(); j++){
            pair<int,int> coor = v[str[0]-'a'][i];
            if(check(str, coor, 0)){
                cout << str << " true" << "\n";   
            }
            else{
                cout << str << " false" << "\n";
            }
        }
        for(int j = 0; j < 101; j++){
            for(int k = 0; k < 101; k++)
                visited[j][k] = 0;
        }
    }
    return 0;
}
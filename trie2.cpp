
int trie[100001][26];
int cnt[100001][26];
int idx = 0;
void insert(string s){
    int root = 0;

    for(int i = 0; i < s.length(); i++){
        int chr = s[i] - 'a';
        if(trie[root][chr] == -1){
            ++idx;
            trie[root][chr] = idx;
            cnt[root][chr] = 1;
        }
        else{
            cnt[root][chr]++;
        }
        root = trie[root][chr];
    }
}

int search(string s){
    int root = 0;
    int i = 0;
    while(i < s.length()){
        if(cnt[root][s[i]-'a'] <= 1)
            return i;
        root = trie[root][s[i]-'a'];
        i++;
    }
    return i-1;
}

vector<string> Solution::prefix(vector<string> &A) {
    for(int i = 0; i < 100000; i++)
        for(int j = 0; j < 26; j++){
            trie[i][j] = -1;
            cnt[i][j] = 0;
        }
            
    for(int i = 0; i < A.size(); i++){
        insert(A[i]);
    }
    vector<string> B;
    for(int i = 0; i < A.size(); i++){
        string ss;
        int id = search(A[i]);
        ss = A[i].substr(0, id+1);
        B.push_back(ss);
    }
    return B;
}
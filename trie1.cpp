#include "bits/stdc++.h"
using namespace std;

struct TrieNode{
    bool isleaf;
    TrieNode *children[27];
};

TrieNode *createNode(){
    TrieNode *pnode = new TrieNode[sizeof(TrieNode)];
    if(pnode){
        pnode->isleaf = false;
        for(int i = 0; i < 26; i++){
            pnode->children[i] = NULL;
        }
    }
    return pnode;
}

void insert(TrieNode *root, string temp){
    int len = temp.length();
    int index;

    TrieNode *pcrawl = root;

    for(int i = 0; i < len; i++){
        if(!pcrawl->children[temp[i]-'a'])
            pcrawl->children[temp[i]-'a'] = createNode();
        pcrawl = pcrawl->children[temp[i]-'a'];
    }

    pcrawl->isleaf = true;
}

bool search(TrieNode *root, string temp){
    int c = 0;
    while(c < temp.length() && (root->children[temp[c]-'a'])){
        root = root->children[temp[c]-'a'];
        c++;
    }

    if(c == temp.length())return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    string keys[] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};

    TrieNode *root = createNode();
    for(int i = 0; i < 8;  i++){
        insert(root, keys[i]);
    }

    string in ;
    cin >> in;
    cout << search(root, in);

    return 0;
}
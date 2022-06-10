#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct TrieNode {
    unordered_map<char, TrieNode*>children;
    bool isEnd = false;
};

TrieNode* root;

void insert(string &str) {
    TrieNode* temp = root;
    for(char &ch: str) {
        if(!temp->children.count(ch))
            temp->children[ch] = new TrieNode();
        temp = temp->children[ch];
    }
    temp->isEnd = true;
}

void printAllNodes(TrieNode* trie, string &curr) {
    if(trie->isEnd) {
        cout << curr << "\n";
    }
    for(char ch = 'z' ; ch >= 'a'; ch--) {
        if(trie->children.count(ch)) {
            curr.push_back(ch);
            printAllNodes(trie->children[ch], curr);
            curr.pop_back();
        }
    }
}

void solve(vector<string>&arr) {
    for(string &str: arr)
        insert(str);
    TrieNode* temp = root;
    string s = "";
    printAllNodes(temp, s);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("error.txt", "w", stderr);
    // #endif
    root = new TrieNode();
    vector<string>arr = {
        "their",
        "there",
        "answer",
        "any"
    };
    solve(arr);
    return 0;
}
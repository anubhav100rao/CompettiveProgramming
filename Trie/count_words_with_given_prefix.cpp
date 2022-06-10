#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct TrieNode {
    unordered_map<char, TrieNode*>children;
    bool isEnd = false;
    int cnt = 0;
};

TrieNode* root;

void insert(string &str) {
    TrieNode* temp = root;
    for(char &ch: str) {
        if(!temp->children.count(ch))
            temp->children[ch] = new TrieNode();
        temp = temp->children[ch];
        temp->cnt = temp->cnt + 1;
    }
    temp->isEnd = true;
}

int getCount(vector<string>&arr, string &str) {
    for(string &s: arr)
        insert(s);
    TrieNode* temp = root;
    for(char &ch: str) {
        if(!temp->children.count(ch))
            return 0;
        temp = temp->children[ch];
    }
    return temp->cnt;
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
    vector<string>words = { "apk", "app", "apple",
              "arp", "array" };
    string prefix = "ap";
    cout << getCount(words, prefix);
    return 0;
}
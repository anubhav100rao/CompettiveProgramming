#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct TrieNode {
    unordered_map<char, TrieNode*>children;
    bool isEnd;
    TrieNode() {
        isEnd = false;
    }
};
TrieNode* root;

void insert(string &str) {
    TrieNode* temp = root;
    for(char &ch: str) {
        if(!temp->children.count(ch)) {
            temp->children[ch] = new TrieNode();
        }
        temp = temp->children[ch];
    }
}

bool insertAndCheck(string &str, int k) {
    TrieNode* temp = root;
    for(char &ch: str) {
        if(!temp->children.count(ch)) {
            if(k > 0) return false;
            else {
                temp->children[ch] = new TrieNode();
            }
        }
        temp = temp->children[ch];
        k--;
    }
    temp->isEnd = true;
    return true;
}

string lexicographicallySmallest(vector<string>&arr, string &prefix) {
    insert(prefix);
    int k = prefix.size();
    for(string &str: arr) {
        insertAndCheck(str, k);
    }
    string res;
    TrieNode* temp = root;
    while(true) {
        bool found = false;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(temp->children.count(ch)) {
                temp = temp->children[ch];
                res.push_back(ch);
                found = true;
                if(temp->isEnd) return res;
                break;
            }
        }
        if(!found)
            return "";
    }
    return "-1";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    root = new TrieNode();
    vector<string>arr = {"apple", "appe", "apl", "aapl", "appax"};
    string prefix = "app";

    cout << lexicographicallySmallest(arr, prefix);

    return 0;
}
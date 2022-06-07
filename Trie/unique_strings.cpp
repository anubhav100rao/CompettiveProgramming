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

bool search(string &str) {
    TrieNode* temp = root;
    for(char &ch: str) {
        if(!temp->children.count(ch))
            return false;
        temp = temp->children[ch];
    }
    return temp->isEnd;
}

vector<string>uniqueStrings(vector<string>&arr) {
    vector<string>res;
    for(string &str: arr) {
        if(!search(str)) {
            res.push_back(str);
            insert(str);
        }
    }
    return res;
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
    vector<string>arr = { "geeks", "for",
                           "geek", "ab", "geek",
                           "for", "code", "karega" };
    vector<string>res = uniqueStrings(arr);
    for(auto s: res) cout << s << " ";
    return 0;
}
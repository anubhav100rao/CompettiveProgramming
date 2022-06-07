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
        if(!temp->children.count(ch)) {
            temp->children[ch] = new TrieNode();
        }
        temp = temp->children[ch];
    }
    // temp->isEnd = true;
}

bool search(string &str) {
    TrieNode* temp = root;
    for(char &ch: str) {
        if(!temp->children.count(ch))
            return false;
        temp = temp->children[ch];
    }
    return true;
}

vector<bool>solve(vector<string>&arr, vector<vector<string>>&queries) {
    for(string &str: arr) {
        string temp = "{" + str;
        insert(temp);
        for(int i = str.size() - 1; i>=0; i--) {
            temp = str.substr(i) + "{" + str;
            insert(temp);
        }
    }
    vector<bool>res;
    for(vector<string>&query: queries) {
        string toCheck = query[1] + "{" + query[0];
        res.push_back(search(toCheck));
    }
    return res;
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
    vector<string>arr = {"apple", "app", "biscuit", "mouse", "orange", "bat", "microphone", "mine"};
    vector<vector<string>>queries = {{"a", "e"}, {"a", "p"}};
    auto res = solve(arr, queries);
    for(auto b: res) cout << b << " ";
    return 0;
}
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

int search(string &str) {
    int len = 0;
    TrieNode* temp = root;
    for(char &ch: str) {
        if(!temp->children.count(ch))
            return len;
        temp = temp->children[ch];
        len++;
    }
    return len;
}

int giveLen(vector<string>&arr) {
    int ans = 0;
    for(string &str: arr) {
        int curr = search(str);
        insert(str);
        ans = max(ans, curr);
    }
    return ans;
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
    vector<string>arr = { "geeksforgeeks", "geeks", "geeksforcse" };
    cout << giveLen(arr);
    return 0;
}
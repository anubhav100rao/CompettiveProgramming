#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    struct TrieNode {
        map<char, TrieNode*>children;
        bool isEnd = false;
    };

    TrieNode* root;
    vector<vector<string>>res;
    vector<string>curr_res;

    void insert(string &str) {
        TrieNode* temp = root;
        for(char &ch: str) {
            if(!temp->children.count(ch)) {
                temp->children[ch] = new TrieNode();
            }
            temp = temp->children[ch];
        }
        temp->isEnd = true;
    }

    void dfs(TrieNode* temp, string str) {
        if(curr_res.size() == 3) return;
        if(temp->isEnd) curr_res.push_back(str);
        for(auto &[ch, node]: temp->children)
            dfs(node, str + ch);
    }

    vector<string>getWordsStartingWith(string prefix) {
        TrieNode* temp = root;
        curr_res.clear();
        for(char ch: prefix) {
            if(!temp->children.count(ch))
                return curr_res;
            temp = temp->children[ch];
        }
        dfs(temp, prefix);
        return curr_res;
    }
    

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        for(string &str: products)
            insert(str);
        string prefix = "";
        res.clear();
        for(char &ch: searchWord) {
            prefix.push_back(ch);
            res.push_back(getWordsStartingWith(prefix));
        }
        return res;
    }
};


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
 
    return 0;
}
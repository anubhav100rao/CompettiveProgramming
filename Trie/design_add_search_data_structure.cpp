#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class WordDictionary {
public:

    struct TrieNode {
        unordered_map<char, TrieNode*>child;
        bool isEnd = false;
    };
    
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        for(char &ch: word) {
            if(!temp->child.count(ch)) {
                temp->child[ch] = new TrieNode();
            }
            temp = temp->child[ch];
        }
        temp->isEnd = true;
    }
    
    bool dfs(string &str, TrieNode* temp, int idx) {
        if(idx == str.size() and temp->isEnd) return true;
        if(str[idx] == '.') {
            bool res = false;
            for(auto &[ch, node]: temp->child) {
                res = res || dfs(str, node, idx + 1);
                if(res)
                    return true;
            }
            return res;
        }
        if(temp->child.count(str[idx])) {
            return dfs(str, temp->child[str[idx]], idx + 1);
        }
        return false;
    }

    bool search(string word) {
        TrieNode* temp = root;
        return dfs(word, temp, 0);
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
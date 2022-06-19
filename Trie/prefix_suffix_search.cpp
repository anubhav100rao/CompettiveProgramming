#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class WordFilter {
public:

    struct TrieNode {
        unordered_map<char, TrieNode*>child;
        set<int, greater<int>>endings;
    };

    TrieNode* root_prefix;
    TrieNode* root_suffix;

    void insert(string &str, int idx, TrieNode* root) {
        TrieNode* temp = root;
        for(char &ch: str) {
            if(!temp->child.count(ch)) {
                temp->child[ch] = new TrieNode();
            }
            temp = temp->child[ch];
            temp->endings.insert(idx);  
        }
    }

    TrieNode* search(string &str, TrieNode* root) {
        TrieNode* temp = root;
        for(char &ch: str) {
            if(!temp->child.count(ch)) {
                return NULL;
            }
            temp = temp->child[ch];
        }
        return temp;
    }

    vector<string>words;

    WordFilter(vector<string>& words) {
        root_prefix = new TrieNode();
        root_suffix = new TrieNode();
        this->words = words;
        for(int i = 0; i<words.size(); i++) {
            insert(words[i], i, root_prefix);
            reverse(words[i].begin(), words[i].end());
            insert(words[i], i, root_suffix);
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* p = search(prefix, root_prefix);
        if(!p) return -1;
        reverse(suffix.begin(), suffix.end());
        TrieNode *s = search(suffix, root_suffix);
        if(!s) return -1;

        for(auto itr = p->endings.begin(); itr != p->endings.end(); itr++) {
            if(s->endings.count(*itr)) {
                return *itr;
            }
        }
        
        return -1;
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
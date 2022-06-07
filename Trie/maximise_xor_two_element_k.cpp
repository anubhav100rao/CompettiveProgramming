#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        this->child[0] = NULL;
        this->child[1] = NULL;
    }
};

TrieNode* root;

void insert(int x) {
    TrieNode* temp = root;
    bitset<32>bs(x);
    for(int i = 30; i>=0; i--) {
        if(!temp->child[bs[i]]) {
            temp->child[bs[i]] = new TrieNode();
        }
        temp = temp->child[bs[i]];
    }
}

int findMaxXorK(int k) {
    int ans = 0;
    TrieNode* temp = root;
    bitset<30>bs(k);
    for(int j = 30; j>=0; j--) {
        if(temp->child[!bs[j]]) {
            ans += (1LL << j);
            temp = temp->child[!bs[j]];
        } else {
            temp = temp->child[bs[j]];
        }
    }
    return ans;
}

int maxXor(vector<int>&arr, int k) {
    for(int i: arr)
        insert(i);
    int ans = 0;
    for(int i: arr)
        ans = max(ans, findMaxXorK(i ^ k));
    return ans;
}

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
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct TrieNode {
    TrieNode* child[2];
    bool isEnd;

    TrieNode() {
        child[0] = child[1] = NULL;
        isEnd = false;
    }
};

TrieNode* root;

void insertTrie(int x) {
    TrieNode* temp = root;
    for(int i = 30; i>=0; i--) {
        bool flag = (x & (1 << i)) ? true: false;
        if(flag) {
            if(!temp->child[1]) {
                temp->child[1] = new TrieNode();
            }
            temp = temp->child[1];
        } else {
            if(!temp->child[0]) {
                temp->child[0] = new TrieNode();
            }
            temp = temp->child[0];
        }
    }
}

int search(int x) {
    int ans = 0;
    TrieNode* temp = root;
    for(int i = 30; i>=0; i--) {
        if(temp == NULL) {
            cout << "iski ummed nhi thi\n";
            return ans;
        }
        bool flag = (x & (1 << i));
        if(flag) {
            if(temp->child[0]) {
                ans |= (1 << i);
                temp = temp->child[0];
            } else {
                temp = temp->child[1];
            }
        } else {
            if(temp->child[1]) {
                ans |= (1 << i);
                temp = temp->child[1];
            } else {
                temp = temp->child[0];
            }
        }
    }
    return ans;
}

int maxXorPair(vector<int>&arr) {
    int n = arr.size();
    int ans = 0;
    insertTrie(arr[0]);
    for(int i = 1; i<n; i++) {
        ans = max(ans, search(arr[i]));
        insertTrie(arr[i]);
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
    vector<int>arr = {1, 2, 3, 4};
    cout << maxXorPair(arr);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    map<int, int>mask;
    int create_mask(string &str) {
        int num = 0;
        for(char &ch: str)
            num |= (1 << (ch - 'a'));
        return num;
    }

    void dfs(int node, int &cnt) {
        cnt += mask[node];
        mask.erase(node);

        for(int i = 0; i<26; i++) {
            int remove_add = node ^ (1 << i);
            if(mask.count(remove_add)) {
                dfs(remove_add, cnt);
            }
            for(int j = i+1; j<26; j++) {
                if(((node >> i) & 1) != ((node >> j) & 1)) {
                    int replace = node ^ (1 << i) ^ (1 << j);
                    if(mask.count(replace))
                        dfs(replace, cnt);
                }
            }
        }
    }

    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();

        for(int i = 0; i<n; i++) {
            mask[create_mask(words[i])]++;
        }

        int tot = 0, mx = 0;
        while(!mask.empty()) {
            int cnt = 0;
            tot++;
            auto [a, b] = *mask.begin();
            dfs(a, cnt);
            mx = max(mx, cnt);
        }

        return {tot, mx};
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
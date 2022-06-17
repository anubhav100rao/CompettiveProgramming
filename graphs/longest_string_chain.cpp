#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    unordered_map<string, int>fre;
    unordered_map<string, int>level;
    unordered_map<int, vector<string>>adj;

    bool good(string &a, string &b) {
        assert(a.size() + 1 == b.size());
        int i = 0, j = 0;
        int cnt = 0;
        while(i < a.size() and j < b.size()) {
            if(a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
                cnt++;
            }
        }
        return cnt <= 1;
    }

    void bfs1(string node) {
        fre[node]--;
        queue<string>q;
        q.push(node);
        level[node] = 1;

        while(!q.empty()) {
            string curr = q.front(); q.pop();
            for(char ch = 'a'; ch <= 'z'; ch++) {
                string temp = ch + curr;
                if(fre[temp] > 0) {
                    fre[temp]--;
                    q.push(temp);
                    level[temp] = level[curr] + 1;
                }
                for(int i = 1; i<temp.size(); i++) {
                    swap(temp[i-1], temp[i]);
                    if(fre[temp] > 0) {
                        fre[temp]--;
                        q.push(temp);
                        level[temp] = level[curr] + 1;
                    }
                }
            }
        }
    }

    void bfs(string node) {
        fre[node]--;
        queue<string>q;
        q.push(node);
        level[node] = 1;
        while(!q.empty()) {
            string curr = q.front(); q.pop();
            for(string &str: adj[curr.size() + 1]) {
                // cout << curr << " " << str << "\n";
                if(fre[str] > 0 and good(curr, str)) {
                    cout << str << "\n";
                    fre[str]--;
                    level[str] = level[curr] + 1;
                    q.push(str);
                }
            }
        }
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const auto &a, const auto &b) {
            return a.size() < b.size();
        });
        for(string &word: words) {
            fre[word]++;
            adj[word.size()].push_back(word);
        }
        
        for(string word: words) {
            if(fre[word] > 0) {
                bfs(word);
                cout << "CALLED-BFS\n";
            }
        }
        int ans = 1;
        for(auto &[a, b]: level)
            ans = max(ans, b);

        return ans;
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
    vector<string>words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    Solution sol;
    cout << sol.longestStrChain(words);
    return 0;
}
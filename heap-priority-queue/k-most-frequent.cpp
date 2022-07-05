#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:

    struct compare {
        bool operator()(pair<string, int>&a, pair<string, int>&b) {
            if(a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>hsh;
        for(string &word: words)
            hsh[word]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, compare>q;

        for(auto p: hsh) {
            q.push(p);
        }

        vector<string>res;

        while(k--) {
            res.push_back(q.top().first);
            q.pop();
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
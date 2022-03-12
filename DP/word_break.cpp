#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

bool word_break(string word, set<string>&dict) {
    if(word == "")
        return true;
    for(int i = 1; i <= word.size(); i++) {
        string left = word.substr(0, i);
        string right = word.substr(i);
        if(dict.find(left) != dict.end() && word_break(right, dict))
            return true;
    }
    return false;
}

bool word_break_dp(string word, set<string>&dict) {
    vector<bool> dp(word.size() + 1, false);
    dp[0] = true;
    for(int i = 1; i <= word.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j] && dict.find(word.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[word.size()];
}

bool word_break_dp1(string word, set<string>&dict) {
    vector<bool> dp(word.size() + 1, false);
    dp[0] = true;
    for(int i = 1; i<=word.size(); i++) {
        for(int j = 0; j<i; j++) {
            string right = word.substr(j, i-j);
            if(dp[j] and dict.count(right)) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[word.size()];
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
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     * Given a string S, 
     * find the length of the longest substring T that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        if(k == 0) return 0; // this condition is must
        if(s.size() <= k) // optimisation
            return s.size();
        // write your code here
        int ans = 0;
        map<char, int>seen;
        map<int, char>hsh;
        int start = -1;

        for(int i = 0; i<s.size(); i++) {
            if(seen.size() == k and !seen.count(s[i])) {
                auto [a, b] = *hsh.begin();
                start = a;
                seen.erase(b);
                hsh.erase(hsh.begin());
            }

            ans = max(ans, i - start);
            if(seen.count(s[i])) {
                hsh.erase(seen[s[i]]);
            }
            seen[s[i]] = i;
            hsh[i] = s[i];
        }
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
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution1 {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0;

        set<int>seen;
        int ans = 0;

        while(r < n) {
            if(seen.count(nums[r])) {
                while(nums[l] != nums[r]) {
                    seen.erase(nums[l]);
                    sum -= nums[l++];
                } sum -= nums[l++];
            }
            seen.insert(nums[r]);
            sum += nums[r++];
            ans = max(ans, sum);
        }
        return ans;
    }
};


class Solution2 {
public:

    int solve_exactly_k(vector<int>&nums, int k) {
        if(k == 0) return 0;
        map<int, int>seen;
        int cnt = 0;
        map<int, int>hsh_idx;
        int start = -1;
        for(int i = 0; i<nums.size(); i++) {
            if(seen.size() == k and !seen.count(nums[i])) {
                auto [a, b] = *hsh_idx.begin();
                hsh_idx.erase(hsh_idx.begin()); seen.erase(b);
                start = a;
            }
            if(seen.count(nums[i])) {
                hsh_idx.erase(seen[nums[i]]);
            }
            seen[nums[i]] = i;
            hsh_idx[i] = nums[i];
            cnt += i - start;
        }
        
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve_exactly_k(nums, k) - solve_exactly_k(nums, k - 1);
    }
};

class Solution3 {
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

class Solution4 {
public:
    // length of longest substring with atmax two distinct characters
    int solve(string &str) {
        map<char, int>seen;
        char pr = '$';
        int start = -1;
        int ans = 0;
        for(int i = 0; i<str.size(); i++) {
            if(seen.size() == 2 and !seen.count(str[i])) {
                int curr_min = 1e9;
                char toDel = '$';
                for(auto &[a, b]: seen) {
                    if(b < curr_min) {
                        curr_min = b;
                        toDel = a;
                    }
                }
                seen.erase(toDel);
                start = curr_min;
            }

            seen[str[i]] = i;
            ans = max(ans, i - start);
        }

        return ans;
    }
};

class Solution5 {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>seen;
        int start = -1, ans = 0;
        for(int i = 0; i<s.size(); i++) {
            if(seen.count(s[i]))
                start = max(start, seen[s[i]]);
            seen[s[i]] = i;
            ans = max(ans, i - start);
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
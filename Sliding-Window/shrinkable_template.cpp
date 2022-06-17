#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

/**
 * int i = 0, j = 0, ans = 0;
 * for (; j < N; ++j) {
 *   CODE: use A[j] to update state which might make the window invalid
 * for (; invalid(); ++i) { // when invalid, keep shrinking the left edge until it's valid again
 *          CODE: update state using A[i]
 * }
 *  ans = max(ans, j - i + 1); // the window [i, j] is the maximum window we've found thus far
 * }  
 * return ans;
*/

class Solution1 {
    /**
     * in this problem we have to count number of substrings
     * which contain all vowels
    */
public:
    bool isVowel(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
    int solve(string &word, int goal) { // returns at most goal number of unique substrings
        unordered_map<char, int>cnt;
        int n = word.size();
        int ans = 0;
        for(int i = 0, j = 0; j < n; j++) {
            if(!isVowel(word[j])) {
                i = j + 1;  
                cnt.clear();
                continue;
            }
            cnt[word[j]]++;
            for(;cnt.size() > goal; i++) {
                if(--cnt[word[i]] == 0)
                    cnt.erase(word[i]);
            }
            ans += (j - i + 1);
        }
        return ans;
    }
    
    int countVowelSubstrings(string word) {
        return solve(word, 5) - solve(word, 4);
    }
};

class Solution2 {
    /**
     * subarray with k different integers
    */
public:

    int solve(vector<int>&nums, int k) {
        unordered_map<int, int>cnt;
        int ans = 0;
        int n = nums.size();
        for(int i = 0, j = 0; j<n; j++) {
            cnt[nums[j]]++;
            for(;cnt.size() > k; i++) {
                if(--cnt[nums[i]] == 0)
                    cnt.erase(nums[i]);
            }
            ans += (j - i + 1);
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};


class Solution3 {
    /**
     * count subarrays with sum = goal
    */
public:
    int solve(vector<int>&arr, int goal) {
        int ans = 0, sum = 0;
        for(int i = 0, j = 0; j<arr.size(); j++) {
            sum += arr[j];
            while(sum > goal) {
                sum -= arr[i++];
            }
            ans += (j - i + 1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
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
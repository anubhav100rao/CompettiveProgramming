#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int>fre;
        ListNode* temp = headA;
        while (temp != NULL)
        {
            fre[temp]++;
            temp = temp->next;
        }

        temp = headB;
        while (temp != NULL)
        {
            fre[temp]++;
            temp = temp->next;
        }

        for(auto [a, b]: fre)
            if(b > 1)
                return a;
        return NULL;
    }
};


class Solution2 {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int>hsh;
        for(int i = 0; i<list2.size(); i++)
            hsh[list2[i]] = i;
        
        map<int, vector<string>>pos;
        for(int i = 0; i<list1.size(); i++) {
            if(hsh.count(list1[i])) {
                pos[i + hsh[list1[i]]].push_back(list1[i]);
            }
        }
        for(auto [a, b]: pos)
            return b;
        return {};
    }
};

class Solution3 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n - 1; i++) {
            nums.push_back(nums[i]);
        }
        stack<int>s;
        vector<int>res(2*n - 1, -1);
        for(int i = 0; i < n + n - 1; i++) {
            while(!s.empty() and nums[s.top()] < nums[i]) {
                int x = s.top(); s.pop();
                res[x] = nums[i];
            }
            s.push(i);
        }

        vector<int>ans;
        for(int i = 0; i<n; i++)
            ans.push_back(res[i]);
        return ans;
    }
};

class Solution4 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int>s;
        map<int, int>nbe;
        for(int i = 0; i<n; i++) {
            while(!s.empty() and nums2[s.top()] < nums2[i]) {
                int x = s.top(); s.pop();
                nbe[nums2[x]] = nums2[i];
            }
            s.push(i);
        }
        vector<int>res;
        for(int i = 0; i<nums1.size(); i++)
            if(nbe.count(nums1[i]))
                res.push_back(nbe[nums1[i]]);
            else
                res.push_back(-1);
        return res;
    }
};

class Solution {
public:
    vector<int>getDigits(int n) {
        vector<int>dig;
        while(n) {
            dig.push_back(n % 10);
            n /= 10;
        }
        reverse(dig.begin(), dig.end());
        return dig;
    }
    int constructNum(vector<int>dig) {
        int ans = 0;
        int base = 1;
        reverse(dig.begin(), dig.end());
        for(const int &d: dig) {
            ans += d * base;
            base *= 10;
        }
        return ans;
    }
    int ptaNhiMkyaKrRhaTha(int n) {
        vector<int>digits = getDigits(n);
        int sz = digits.size();
        vector<int>nbe(sz, -1);
        stack<int>s;
        for(int i = 0; i<sz; i++) {
            while(!s.empty() and digits[s.top()] < digits[i]) {
                int x = s.top(); s.pop();
                nbe[x] = i;
            }
            s.push(i);
        }
        bool flag = true;
        int idx = -1;
        for(int i = sz - 1; i>=0; i--) {
            if(nbe[i] != -1 and flag) {
                flag = false;
                int next = nbe[i];
                nbe[i] = digits[next];
                nbe[next] = digits[i];
                idx = next;
            } else {
                nbe[i] = digits[i];
            }
        }

        if(flag) return -1;

        sort(nbe.begin() + idx, nbe.end());

        return constructNum(nbe);
    }
    
    int nextGreaterElement(int n) {
        string dig = to_string(n);
        next_permutation(dig.begin(), dig.end());
        long long res = stoll(dig);
        return (res > INT_MAX || res <= n) ? -1: res;
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
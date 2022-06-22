#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto mid_ptr = nums.begin() + n / 2;      
        nth_element(nums.begin(), mid_ptr, nums.end());
        int mid = *mid_ptr;
        int i = 0, j = 0, k = n - 1;


        #define A(i) nums[(1+2*(i)) % (n|1)]

        while(j <= k) {
            if(A(j) > mid) swap(A(i++), A(j++));
            else if(A(j) < mid) swap(A(j), A(k--));
            else j++; 
        }
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
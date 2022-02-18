#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>res;
        if(x <= arr[0]) {
            for(int i = 0; i<k; i++) {
                res.push_back(arr[i]);
            }
            return res;
        }
        if(x >= arr[n-1]) {
            for(int i = n-1; i>= n - k; i--) {
                res.push_back(arr[i]);
            }
            reverse(res.begin(), res.end());
            return res;
        }
        int l = 0, r = n-1, p = 0;
        
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if(arr[mid] < x) {
                l = mid;
            } else {
                r = mid;
            }
        }

        if(abs(arr[l] - x) <= abs(arr[r] - x)) p = l;
        else p = r;

        cout << p << '\n';
        res.push_back(arr[p]);
        k--;
        int itr1 = p-1;
        int itr2 = p+1;
        while(itr1 >= 0 and itr2 < n and k > 0) {
            if(abs(x - arr[itr1]) < abs(x - arr[itr2])) {
                res.push_back(arr[itr1]);
                k--;
                itr1--;
            } else if(abs(x - arr[itr1]) > abs(x - arr[itr2])) {
                res.push_back(arr[itr2++]);
                k--;
            } else {
                res.push_back(arr[itr1--]);
                k--;
            }
        }
        while(itr1 >= 0 and k > 0) {
            res.push_back(arr[itr1--]);
            k--;
        }
        while(itr2 < n and k > 0) {
            res.push_back(arr[itr2++]);
            k--;
        }
        sort(res.begin(), res.end());
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
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>a;
    sort(arr, arr + n);
    int l = 0, r =  n-1, res = -1;
    
    while(r - l >= 0) {
        int mid = l + (r - l) / 2;
        if(arr[mid] >= x) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    } 
    if(res == -1 || arr[res] != x) res = -1;
    a.push_back(res);
    l = 0, r = n-1, res = -1;
    while(r - l >= 0) {
        int mid = l + (r - l) / 2;
        if(arr[mid] <= x) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(res == -1 || arr[res] != x) res = -1;
    a.push_back(res);
    return a;
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
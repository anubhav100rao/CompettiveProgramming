#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

bool findPair(int arr[], int size, int n){
    //code
    sort(arr, arr + size);
    for(int i = 0; i<size; i++) {
        int l = i + 1, r = size - 1;
        
        while(r - l >= 0) {
            int mid = l + (r - l) / 2;
            if(arr[mid] - arr[i] == n)
                return true;
            if(arr[mid] - arr[i] > n) r = mid - 1;
            else l = mid + 1;
        }
    }
    
    return false;
    
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
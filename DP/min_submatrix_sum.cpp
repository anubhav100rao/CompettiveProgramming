#include <bits/stdc++.h> 
using namespace std;
#define ll long long

#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

// idea is to maintain left and colummn, and find the row range using kadane algorithm

int kadane(vector<int>&arr, int &start, int &finish) {
    int sm = 0, minSum = INT_MAX;
    finish = -1;
    int local_start = 0;
    int n = arr.size();
    for(int i = 0; i<n; i++) {
        sm += arr[i];
        if(sm > 0) {
            sm = 0;
            local_start = i + 1;
        } else if(sm <  minSum) {
            minSum = sm;
            start = local_start;
            finish = i;
        }
    }
    if(finish != -1)
        return minSum;
    minSum = arr[0], start = finish = 0;
    for(int i = 0; i<n; i++) {
        if(arr[i] < minSum) {
            minSum = arr[i];
            start = i;
            finish = i;
        }
    }
    return minSum;
}

int solve(vector<vector<int>>&arr) {
    int n = arr.size(), m = arr[0].size();
    int minSum = INT_MAX;
    int finalLeft , finalRight, finalTop, finalBottom;
    
    vector<int>temp(n, 0);
    int start, finish;
    for(int left = 0; left < m; left++) {
        temp = vector<int>(n, 0);
        for(int right = left; right < m; right++) {
            for(int i = 0; i<n; i++) {
                temp[i] += arr[i][right];
            }
            int curr_sum = kadane(temp, start, finish);

            if(curr_sum < minSum) {
                minSum = curr_sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    cout << "from (" << finalTop << ", "
     << finalLeft << ") to (" << finalBottom << ", " << finalRight << ")\n";
    return minSum; 
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    vector<vector<int>>arr = { { 1, 2, -1, -4, -20 },
                        { -8, -3, 4, 2, 1 },
                        { 3, 8, 10, 1, 3 },
                        { -4, -1, 1, 7, -6 } };
    cout << solve(arr);
    return 0;
}
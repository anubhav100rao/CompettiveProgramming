// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        using pii = pair<int, int>;
        vector<pii>A;
        for(int i = 0; i<n; i++) {
            A.push_back({arr[i], -1});
            A.push_back({dep[i], 1});
        }
        sort(A.begin(), A.end());
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i<2*n; i++) {
            // cout << A[i].first << " " << A[i].second << "\n";
            if(A[i].second == -1) cnt++;
            else cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
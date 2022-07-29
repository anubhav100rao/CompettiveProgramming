
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


class Solution 
{
    public:
    
    struct comparator {
        bool operator()(Job a, Job b) {
            return a.profit < b.profit;
        }  
    };
    
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
    
        sort(arr, arr + n, [&](Job a, Job b) {
            return a.dead < b.dead;
        });
        
        int ans = 0, cnt = 0;
        
        priority_queue<Job, vector<Job>, comparator>pq;
        
        for(int i = n - 1; i>= 0; i--) {
            int slots = arr[i].dead;
            if(i != 0)
                slots -= arr[i-1].dead;
            
            pq.push(arr[i]);
            while(slots > 0 and !pq.empty()) {
                Job currJob = pq.top(); pq.pop();
                slots--;
                cnt++;
                ans += currJob.profit;
            }
        }
        
        return {cnt, ans};
    } 
};

int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;

        cin >> n;
        Job arr[n];
        
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
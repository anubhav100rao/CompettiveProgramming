#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    double mincostToHireWorkersTle(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        double ans = 1e9;
        for(int i = 0; i < n; i++) {
            double factor = (wage[i] + 0.0) / quality[i];
            vector<double>curr;
            for(int i = 0; i < n; i++) {
                double cost = factor * quality[i];
                if(cost >= wage[i]) {
                    curr.push_back(cost);
                }
            }
            
            if(curr.size() >= k) {
                sort(curr.begin(), curr.end());
                double res = 0;
                for(int i = 0; i < k; i++) {
                    res += curr[i];
                }
                ans = min(ans, res);
            }
        }    

        return ans;  
    }

    struct Worker {
        int quality;
        int wage;
        double ratio;

        Worker(int quality, int wage) {
            this->quality = quality;
            this->wage = wage;
            this->ratio = (wage + 0.0) / quality;
        }

        bool operator<(Worker &worker) {
            return ratio < worker.ratio;
        }
    };

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();

        vector<Worker>workers;

        for(int i = 0; i < n; i++) {
            workers.push_back(Worker(quality[i], wage[i]));
        } 
        
       

        double ans = 1e9;

        sort(workers.begin(), workers.end());
        
         for(auto worker: workers) {
            cout << worker.quality << " " << worker.wage << " " << worker.ratio << '\n';
        }

        priority_queue<int>pq;

        int preSum = 0;
        
        for(Worker worker: workers) {
            pq.push(worker.quality);
            preSum += worker.quality;
            if(pq.size() > k) {
                preSum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k) {
                ans = min(ans, preSum * worker.ratio);
            }
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
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
    int n, m;
    int ans = 0;
    vector<vector<int>>students, mentors;
public:

    void find_permutations(int idx) {
        if(idx >= n) {
            int curr = 0;
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<m; j++) {
                    if(students[i][j] == mentors[i][j]) curr++;
                }
            }
            if(curr > ans)
                ans = curr;
            return;
        } 
        
        for(int i = idx; i<n; i++) {
            swap(students[i], students[idx]);
            find_permutations(idx+1);
            swap(students[i], students[idx]);
        }
    }

    int cleanSolution() {
        int res = 0;
        vector<int>pos(n, 0);
        iota(pos.begin(), pos.end(), 0);
        
        do {
            int curr = 0;
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<m; j++) {
                    int new_i = pos[i];
                    if(students[new_i][j] == mentors[i][j])
                        curr++;
                }
            }
            if(curr > res)
                res = curr;
        } while(next_permutation(pos.begin(), pos.end()));
        
        return res;
    }


    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n = students.size(), m = students[0].size();
        this->students = students;
        this->mentors = mentors;
        // I have to generate all permutation of students array and check it with mentors array
        find_permutations(0);
        // return cleanSolution();
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
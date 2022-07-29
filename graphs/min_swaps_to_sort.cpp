#include<bits/stdc++.h>
using namespace std;



class DSU {
public:
    vector<int>parent, _size;
    DSU(int n) {
        parent.resize(n+1);
        _size.resize(n+1, 1);
        for(int i = 1; i<=n; i++) parent[i] = i;
    }
    int find_parent(int a) {
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent[a]);
    }
    void union_sets(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);
        if(a != b) {
            if(_size[a] < _size[b]) swap(a, b);
            parent[b] = a;
            _size[a] += _size[b];
        }
    }
    bool same_set(int a, int b) {
        return find_parent(a) == find_parent(b);
    }
};

class Solution {
    public:
    int minSwaps(vector<int>&nums) {
        int n = nums.size();
        DSU dsu(n);
        vector<int>sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<bool>visited(n, false);

        map<int, int>location;
        for(int i = 0; i<n; i++)
            location[sorted[i]] = i;


        for(int i = 0; i<n; i++) {
            if(nums[i] == sorted[i]) {
                continue;
            }
            if(!visited[i]) {
                visited[i] = true;
                int j = location[nums[i]];
                while(!visited[j]) {
                    visited[j] = true;
                    dsu.union_sets(i, j);
                    j = location[nums[j]];
                }
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++) {
            if(dsu.find_parent(i) == i) {
                ans += dsu._size[i] - 1;
            }
        }
        return ans;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
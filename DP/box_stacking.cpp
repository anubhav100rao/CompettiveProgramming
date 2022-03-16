#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Box {
public:
    int length;
    int width;
    int height;
};

vector<int>dp;

int findMaxHeight(vector<Box>&boxes, int last_index, int index) {
    if(index < 0)
        return 0;
    if(dp[index] != -1)
        return dp[index];
    int maxHeight = 0;
    for(int i = index; i>=0; i--) {
        if(last_index == -1
            ||
            (boxes[i].length < boxes[last_index].length and boxes[i].width < boxes[last_index].width)
        ) {
            maxHeight = max(maxHeight, findMaxHeight(boxes, i, i-1) + boxes[i].height);
        }
    }
    return dp[index] = maxHeight;
}

int maxStackHeight(int height[], int width[], int length[], int n) {
    vector<Box>boxes;
    dp = vector<int>(3*n + 5, -1);
    for(int i = 0; i<n; i++) {
        Box box;
        box.length = max(length[i], width[i]);
        box.width = min(length[i], width[i]);
        box.height = height[i];
        boxes.push_back(box);

         // First rotation of box
        box.height = width[i];
        box.length = max(length[i], height[i]);
        box.width = min(length[i], height[i]);
        boxes.push_back(box);
 
        // Second rotation of box
        box.height = length[i];
        box.length = max(width[i], height[i]);
        box.width = min(width[i], height[i]);
        boxes.push_back(box);
    }

    sort(boxes.begin(), boxes.end(), [&](const Box &a, const Box &b) {
        return (a.length * a.width) < (b.length * b.width);
    });
    
    return findMaxHeight(boxes, -1, boxes.size() - 1);
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
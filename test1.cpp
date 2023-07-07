#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct TreeNode {
    TreeNode *left, *right;

};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        int mx=0;
         while(!q.empty()){
            int c=q.size();
             int s=q.front().second;
             int e=q.back().second;
             int h=e-s+1;
            mx=max(mx,(h));
            for(int i=0;i<c;i++)
            {  TreeNode* rum=q.front().first;
                long long int x=q.front().second;
                q.pop();
                if(rum->left!=NULL)
                q.push({rum->left,1LL*(2*x+1)});
                if(rum->right!=NULL)
                q.push({rum->right,1LL*(2*x+2)});
            }
         }
         return mx;
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
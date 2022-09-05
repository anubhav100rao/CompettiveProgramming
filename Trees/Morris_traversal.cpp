#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int>getInOrder(TreeNode* root) {

    TreeNode* curr = root;
    vector<int>inOrder;

    while(curr) {
        if(curr->left == NULL) {
            inOrder.push_back(curr->val);
            curr = curr->right;
        } else {

            TreeNode* prev = curr->left;

            while(prev->right and prev->right != curr) {
                prev = prev->right;
            }

            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } else {
                inOrder.push_back(curr->val);
                prev->right = NULL;
                curr = curr->right;
            }

        }
    }

    return inOrder;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
 
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);

    vector<int>inOrder = getInOrder(root);

    for(const int i: inOrder) cout << i << " ";

    return 0;
}
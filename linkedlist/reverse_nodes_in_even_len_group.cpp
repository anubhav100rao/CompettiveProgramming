#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:


    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        vector<ListNode*>nodes;
        ListNode* temp = head;
        while(temp != NULL) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int n = nodes.size();
        bool flag = false;
        for(int i = 0; i<n; i++) {
            
        }


        return head;
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
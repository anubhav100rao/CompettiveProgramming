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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);  
        ListNode* curr = head;

        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val: 0;
            int y = l2 ? l2->val: 0;

            curr->next = new ListNode(0);

            curr->val = (carry + x + y) % 10;
            carry = (carry + x + y) / 10;
            curr = curr->next;
            
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
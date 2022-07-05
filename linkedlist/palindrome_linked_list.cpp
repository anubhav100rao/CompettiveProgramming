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

    void print_list(ListNode* head) {
        ListNode* temp = head;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        } cout << "\n";
    }

    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        print_list(head);

        ListNode *slow = head, *fast = head;

        while(fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = reverse(slow);

        print_list(head);

        while(slow != NULL and slow->val == head->val) {
            slow = slow->next;
            head = head->next;
        }

        return slow == NULL;

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
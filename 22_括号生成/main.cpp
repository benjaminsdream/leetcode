#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {

    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // ListNode *l1 = nullptr;
    // ListNode* l2 = nullptr;

    // ListNode *l1 = nullptr;
    // ListNode *l2 = new ListNode(0);

    ListNode *newHead = Solution().mergeTwoLists(l1, l2);
    ListNode *p = newHead;
    while(p != nullptr){
        cout << p->val << "->";
        p = p->next; 
    }
    cout << endl; 
    return 0;
}
#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;

        ListNode* p1 = l1;
        ListNode* p2 = l2;  // 不要破坏原来的头结点
        if(l1->val <= l2->val){
            dummy->next = l1;
            p = l1;
            p1 = p1->next;
        } else {
            dummy->next = l2;
            p = l2;
            p2 = p2->next;
        }
        while( p1 != nullptr &&  p2 != nullptr){
            if(p1->val <= p2->val){
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = p1 == nullptr ? p2: p1;
        return dummy->next;
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
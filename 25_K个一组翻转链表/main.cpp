#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if(!head) return nullptr;
    //     if(k<=0) return nullptr;
    //     if(k==1) return head;//不用翻转
    //     auto dummy = new ListNode();
    //     dummy->next = head;
    //     int i = k;
    //     auto newHead = dummy;
    //     while(i--) {
    //         // cout << "i:" << i << " newHead:" << newHead->val <<endl;
    //         newHead = newHead->next;
    //         if(!newHead) return head; // 不足K个节点，不需要翻转，返回head
    //     }
    //     dummy->next = newHead; //此时的p就是头结点
    //     auto headNext = head->next;// 先保存headNext
    //     head->next = reverseKGroup(newHead->next, k);
    //     auto pre = head;
    //     auto cur = headNext;
    //     // cout << "newHead:" << newHead->val<<endl;
    //     // cout << "head->next:" << head->next->val<<endl;
    //     // cout << "pre:" << pre->val<<endl;
    //     // cout << "cur:" << cur->val<<endl;
    //     while(cur!=newHead) {//这里不能像常规的翻转链表到最后一个NULL，因为有可能变化
    //         // cout << "cur:"<<cur->val<<" pre:"<<pre->val<<" newHead:"<<newHead->val<<endl;
    //         auto curNext = cur->next;
    //         cur->next = pre;

    //         pre = cur;
    //         cur = curNext;
    //     }
    //     newHead->next = pre;
    //     // cout << endl << endl;
    //     return newHead;
    // }
    // reverse 翻转链表
    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail){
        // pre 前指针
        // cur 当前指针
        ListNode *pre = tail->next;
        ListNode *cur = head;
        while(pre!=tail){
            //delete
            auto next = cur->next;
            cur->next = pre;

            //shift 
            pre = cur;
            cur = next;
        } 
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // dummy -> next = head
        // pre = dummy
        // head 非空就一直执行  直到某次循环不足k个退出
        // head 指向每次的头
        // tail 指向每次的尾
        auto dummy = new ListNode();
        dummy->next = head;
        ListNode *pre = dummy;
        while(head){
            ListNode* tail = pre; // 前节点，而非head
            for(int i=0; i<k; i++){
                tail = tail->next;
                if(!tail) return dummy->next;//结束
            }
            tie(head, tail) = reverse(head, tail);
            pre->next = head;
            
            pre = tail;
            head = tail->next;//更新下一个head
        }
        return dummy->next;
    }
};
void DisplayList(ListNode* h){
    auto p = h;
    while(p){
        cout << p->val << "->";
        p = p->next;
    }
    cout << endl;
    return ;
}
int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    DisplayList(l1);

    ListNode *newHead = Solution().reverseKGroup(l1,2);
    ListNode *p = newHead;

    DisplayList(p);
    return 0;
}
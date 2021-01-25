#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void DisplayList(ListNode* head){
    auto p = head;
    while(p){
        cout << p->val << " -> ";
        p = p->next;        
    }
    cout << endl;
}


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2){
        if(!h1 || !h2 ) return  !h1 ? h2 : h1;
        ListNode* ans = new ListNode();
        ListNode* p = ans;
        while(h1 && h2){
            if(h1->val < h2->val){
                // printf("h1->val[%d] < h2->val[%d]\n");
                p->next = h1;
                h1 = h1->next;
            } else {
                // printf("h1->val[%d] < h2->val[%d]\n");
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        p->next = !h1 ? h2 : h1;
        return ans->next;
    }
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     if(lists.size() == 0){
    //         return nullptr;
    //     }
    //     if(lists.size() == 1){
    //         return lists[0];
    //     }
    //     auto len = lists.size();
    //     auto ans = lists[0];        
    //     for(auto i=1; i<len; i++){
    //         // DisplayList(lists[i]);
    //         ans = merge(ans, lists[i]);
    //         // cout << "i:" << i << endl;
    //         // DisplayList(ans);
    //     }
    //     return ans;
    // }
    // ListNode* merge(vector<ListNode*>& lists, int l, int r){
    //     if(l==r) return lists[l];
    //     if(l>r) return nullptr;
    //     int mid = (l+r) / 2;
    //     auto ans = mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
    //     return ans;
    // }
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //    return merge(lists, 0, lists.size()-1);
    // }

    // 优先队列法：
    // 1. 构建队列
    // 2. 循环处理队列，当队列空时退出
    struct One {
        int val; // 必须要有这个val
        ListNode* ptr; // 必须指定这个指针，每次会弹出这个指针
        bool operator < (const One& r) const {
            return val > r.val;
        }
    };
    priority_queue<One> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       
       for(auto* l : lists){
           if(l) q.push({l->val, l});
       }
       ListNode* ans = new ListNode();
       ListNode* tail = ans;
       while(!q.empty()){
           auto top = q.top(); q.pop();
           tail->next = top.ptr;
           tail = tail->next;
           if(top.ptr->next != nullptr) {q.push({top.ptr->next->val, top.ptr->next});}
       }
        return ans->next;
    }

};

int main() {
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(4);
    h1->next->next = new ListNode(5);

    ListNode* h2 = new ListNode(1);
    h2->next = new ListNode(3);
    h2->next->next = new ListNode(4);

    ListNode* h3 = new ListNode(2);
    h3->next = new ListNode(6);

    vector<ListNode*> v = {h1, h2, h3};
    vector<ListNode*> v2;

    ListNode* h4;
    vector<ListNode*> v3 = {h4};
    auto result = Solution().mergeKLists(v2);
    DisplayList(result);    
    return 0;
}
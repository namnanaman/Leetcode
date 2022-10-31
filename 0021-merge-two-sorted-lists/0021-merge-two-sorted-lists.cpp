/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* res = new ListNode(0);
        ListNode* curr = NULL;
        
        while(l1 and l2){
            if(l1->val <= l2->val){
                if(res->next == NULL) res->next = l1;
                else curr->next = l1;
                curr = l1;
                l1 = l1->next;
            }else{
                if(res->next == NULL) res->next = l2;
                else curr->next = l2;
                curr = l2;
                l2 = l2->next;
            }
        }
        
        if(l1){
            curr->next = l1;
            curr = l1;
            l1 = l1->next;
        }
        if(l2){
            curr->next = l2;
            curr = l2;
            l2 = l2->next;
        }
        
        return res->next;
    }
};
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
class cmp
{
    public:
    
};


class Solution {
public:
    
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, Solution> q;
        ListNode *dummy = new ListNode(-1);
        ListNode* tail = NULL;
        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i])
            {
                q.push(lists[i]);
            }
        }
        while(!q.empty())
        {
            ListNode *temp = q.top();
            if(dummy->next == NULL)  {
                dummy->next = temp;
            }else{
                tail->next = temp;
            }
            
            tail = temp;
            q.pop();
            if(temp->next)
            {
                q.push(temp->next);
            }
        }
        
       return dummy->next;
    }
};
// class Compare{
//     public:
//     bool operator()(ListNode* a ,ListNode* b){
//         return a->val > b->val;
//     }
// };

// class Solution {
// public:
    
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
        
//         ListNode* dummy = new ListNode(-1);
//         ListNode* tail = dummy;
        
//         priority_queue<ListNode*, vector<ListNode*>,Compare> q;
        
//         for(int i =0;i < lists.size();i++){
//             q.push(lists[i]);
//         }
        
        
//         while(!q.empty())
//         {
//             ListNode *temp = q.top();
//             tail->next = temp;
//             tail = temp;
//             q.pop();
//             if(temp->next)
//             {
//                 q.push(temp->next);
//             }
//         } 
//         return dummy->next;
        
        
        
        
        
//     }
// };
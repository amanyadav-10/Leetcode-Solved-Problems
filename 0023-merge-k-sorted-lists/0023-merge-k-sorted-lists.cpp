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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        ListNode* res = lists[0];
        for(int i=1;i<lists.size();i++){
            res = merge(res,lists[i]);
        }
        return res;
        
    }
    
    ListNode* merge(ListNode* L1,ListNode* L2){
        if(!L1){
            return L2;
        }
        if(!L2){
            return L1;
        }
        ListNode* head = NULL;
        if(L1->val<L2->val){
            head = L1;
            L1=L1->next;
        }
        else{
            head = L2;
            L2 = L2->next;
        }
        
        ListNode* temp = head;
        
        while(L1 && L2){
            if(L1->val<L2->val){
                temp->next = L1;
                L1=L1->next;
            }
            else{
                temp->next = L2;
                L2 = L2->next;
            }
            temp = temp->next;
        }
        
        if(L1){
            temp->next = L1;
        }
        if(L2){
            temp->next = L2;
        }
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
//       this is a classic algo to determine if there is a cycle in the 
        if(head==NULL or head->next==NULL){
            return false;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow==fast){
                return true;
            }
        }
        return false;
        
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * curr = head;
        ListNode * prev = head;
        while(n--){
            curr=curr->next;
        }
        if(curr==NULL){
            return head->next;
        }
        while(curr->next!=NULL){
            curr = curr->next;
            prev = prev->next;
        }
        
        ListNode* del = prev->next;
        prev->next = prev->next->next;
        
        delete del;
        return head;
    }
};
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
    
    void merge(ListNode* L1, ListNode* L2){
        ListNode* val = L1;
        ListNode* val2 = L2;
        while(val && val2){
            ListNode* temp = val->next;
            ListNode* temp2 = val2->next;
            val->next = val2;
            val2->next = temp ;
            val = temp;
            val2 = temp2;
        }
    }
    
    void reorderList(ListNode* head) {
//         find the middle of the LL 
        ListNode* cur = head;
        ListNode* pre = head;
        while(cur && cur->next){
            cur = cur->next->next;
            pre = pre->next;
        }
        ListNode* head2 = pre->next;
        pre->next = NULL;
        
//         try to reverse the LL 
        ListNode* prev = NULL;
        ListNode* a = head2;
        while(a){
            ListNode* temp = a->next;
            a->next = prev;
            prev = a;
            a = temp;
        }
        
        head2 = prev;
//         this is the second LL that is reverse
        merge(head,head2);
        
        
        
    }
};
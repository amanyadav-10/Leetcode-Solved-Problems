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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prev=new ListNode(0,NULL);
        ListNode* past=new ListNode(0,NULL);
        
        ListNode* curr=head;
        ListNode* pastHead=past;
        ListNode* prevHead=prev;
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        
        
        while(curr!=NULL){
            if(curr->val<x){
                prev->next=curr;
                prev=prev->next;
                
            }
            else{
                past->next=curr;
                past=past->next;
                
            }
            curr=curr->next;
            
        }
        past->next=NULL;
        
        prev->next=pastHead->next;
        return prevHead->next;
        
    }
};
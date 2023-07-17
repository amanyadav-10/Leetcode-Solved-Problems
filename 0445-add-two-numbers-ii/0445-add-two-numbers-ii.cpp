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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//             storing the list in the stack
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        stack<int> s1;
        stack<int> s2;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
            
        }
        
//         now we will create a stack of value for to return the linked list without the need of reversing it
        stack<int> val;
//         we run the loop till the
        ListNode* head=NULL;
        int sum=0;
        int carry=0;
        while(!s1.empty() || !s2.empty() || carry){//if the carry is not equal to one'
            sum=0;
            if(!s1.empty()){
                sum+=s1.top();
                s1.pop();
            }
            
            if(!s2.empty()){
                sum+=s2.top();
                s2.pop();
            }
            
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* node=new ListNode(sum);
            node->next=head;
            head=node;  
            
        } 
        return head;
        
        
        
    }
};
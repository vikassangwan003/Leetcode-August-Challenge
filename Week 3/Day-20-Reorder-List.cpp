/**
Problem : https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3430/
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
**/

//Solution

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
    void reverseList(ListNode* head){
        ListNode* curr=head->next,*second,*prev=NULL;
        while(curr!=NULL){
            second=curr->next;
            curr->next=prev;
            prev=curr;
            curr=second;
        }
        head->next=prev;
    }
    
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        reverseList(slow);
        ListNode* curr=head,*secHalf=slow->next,*rem,*temp;
        slow->next=NULL;
        
        while(curr!=NULL){
            temp=curr->next;
            // cout<<curr->next->val<<" ";
            if(secHalf==NULL)break;
            curr->next=secHalf;
            rem=secHalf->next;
            secHalf->next=temp;
            
            secHalf=rem;
            curr=temp;
        }
        
        
    }
};
 

// link -  https://leetcode.com/problems/merge-two-sorted-lists/

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
      
      //recursion 
      
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else 
        {
            l2->next = mergeTwoLists(l2->next,l1);
            return l2;
        }
        
        
      //iterative approach
      
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        
        ListNode* newhead = NULL;
		    ListNode* newtail = NULL;
        
        if(l1->val > l2->val)
        {
            newhead = l2;
            newtail = l2;
            l2 = l2->next;
        }
        else
        {
            newhead = l1;
            newtail = l1;
            l1 = l1->next;
        }
        
        while(l1 != NULL and l2 != NULL)
        {
            if(l1->val > l2->val)
            {
                newtail->next = l2;
                newtail = newtail->next;
                l2 = l2->next;
            }
            else
            {
                newtail->next = l1;
                newtail = newtail->next;
                l1 = l1->next;
            }
        }
        
        if(l1 != NULL)
        {
            newtail->next = l1;
            l1 = newtail->next;
        }
        else
        {
            newtail->next = l2;
            l2 = newtail->next;
        }
        
        
        return newhead;
        
        
    }
};

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
    ListNode* reverseList(ListNode* node){
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(node != NULL){
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return true;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseList(slow->next);
        
        slow = slow->next;
        
        while(slow != NULL){
            if(head->val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
};
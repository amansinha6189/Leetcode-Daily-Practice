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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = new ListNode();
        ListNode* ans = curr;
        
        bool gotZero = false;
        int sum = 0;
        while(head != NULL){
            if(head->val == 0){
                if(gotZero and sum){
                    curr->next = new ListNode(sum);
                    curr = curr->next;
                    sum = 0;
                }
                gotZero = true;
            }
            
            sum += head->val;
            head = head->next;
        }
        return ans->next;
    }
};
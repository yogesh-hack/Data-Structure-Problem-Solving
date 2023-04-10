// Problem : 61

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
    ListNode* rotateRight(ListNode* head, int k) {
        // check is listnode empty?
        if(!head){
            return NULL;
        }

        // find length of listnode
        int len = 1; // head is avialble
        // Do not change the head position
        ListNode *tail = head;
        while(tail->next){
            len++;
            tail = tail->next;
        }

        // check if k is greater than lenght of ListNode then, do module it
        k = k % len;

        // check rotated `k` is not be 0 if k = 0 then return same Listnode
        if(k == 0){
            return head;
        }

        // rotate k times that mean loop from 0 to lenght - k - 1
        ListNode *newtail = head;
        for(int i=0;i<len - k - 1;i++){
            newtail = newtail->next;
        }

        ListNode *newhead = newtail->next;

        // newtail at last, then next is NULL
        newtail->next = NULL;

        // tail at last of original ListNode connect with head(front)
        tail->next = head;

        return newhead;
        
    }
};

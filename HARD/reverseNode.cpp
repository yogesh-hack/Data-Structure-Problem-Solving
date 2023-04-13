/**
* Definition for singly-linked list.
* struct ListNode {
* int val;
* ListNode *next;
* ListNode() : val(0), next(nullptr) {}
* ListNode(int x) : val(x), next(nullptr) {}
* ListNode(int x, ListNode *next) : val(x), next(ne
* };
*/
class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            //STEP:1 first check if the head of the linked
            // list is NULL or if the list has only one node
            if(head == NULL || head->next == NULL || k == 1)
              return head;
            }
            //STEP:2 count the number of nodes in the linked
            int length = 0;
            ListNode* curr = head;
            while(curr != NULL){
              curr = curr->next;
              length++;
            }
            //STEP:3 create a dummy node that points to the
            // head of the linked list for reversing process
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            //STEP:4 initialize two pointers: pre and tail.
            // pre points to the dummy node,
            // while tail points to the first node of the kListNode* pre = dummy;
            //STEP:5 swap the next pointers of each node
            // in the k-group so that the nodes are reversed
            for(int i=0;i<length/k;i++){
                ListNode* tail = pre->next;
                for(int j=1;j<k;j++){
                    ListNode* next = tail->next;
                    // swapping (reversing)
                    tail->next = next->next;
                    next->next = pre->next;
                    pre->next = next;
                }
                pre = tail;
            }
            //STEP:6 Finally, return the next node of the dummy
            // since the dummy node was only used to simplify th
            // reversing process and is not part of the original
            return dummy->next;
        }
};

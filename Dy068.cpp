// 142. Linked List Cycle II
// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.
  
  
//   Constraints:

// The number of the nodes in the list is in the range [0, 10^4].
// -10^5 <= Node.val <= 10^5
// pos is -1 or a valid index in the linked-list.


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*s=head;
        ListNode*f=head;
        ListNode*ans=NULL;
        while(s && f && f->next){
            s=s->next;
            f=f->next->next;
            if(f==s){
                f=head;
                while(f!=s){
                    f=f->next;
                    s=s->next;
                }
                    ans=s;
                    break;
            }
        }
        return ans;
    }
};

// 382. Linked List Random Node
// Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

// Implement the Solution class:

// Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
// int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.
  
  
//   Constraints:

// The number of nodes in the linked list will be in the range [1, 10^4].
// -10^4 <= Node.val <= 10^4
// At most 10^4 calls will be made to getRandom.


class Solution {
public:
    ListNode* head;
    Solution(ListNode* head) {
        this-> head=head;
    }

    int getRandom() {
        int count = 0,
        res= 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            if (rand() % count == 0) res = curr->val;
            curr = curr->next;
        }
        return res;
    }
};

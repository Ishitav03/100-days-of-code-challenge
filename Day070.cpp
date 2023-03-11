// 109. Convert Sorted List to Binary Search Tree
// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
// height-balanced binary search tree.
  
// Constraints:

// The number of nodes in head is in the range [0, 2 * 10^4].
// -10^5 <= Node.val <= 10^5


class Solution {
public:
    TreeNode* f(ListNode*head,int n){
        if(n<=0) return nullptr;        
        if(n==1) return new TreeNode(head->val);
        
        int mid=n/2;
        ListNode*temp=head;
        while(mid--) temp=temp->next;

        TreeNode*ans=new TreeNode(temp->val,f(head,n/2),f(temp->next,n-n/2-1));
        return ans;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        int n=0;
		ListNode*temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        return f(head,n);
    }
};

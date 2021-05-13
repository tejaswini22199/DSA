>https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/submissions/
```
class Solution {
public:
    ListNode* findMid(ListNode* head)
    {
        if(head==NULL)
            return head;
        ListNode* slow;
        ListNode* fast;
        ListNode* prev;
        prev=NULL;
        slow=head;
        fast=head;
        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL)
        prev->next=NULL;
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
       ListNode* middle;
        middle=findMid(head);
        TreeNode* root;
        root=new TreeNode(middle->val);
        if(head==middle)
            return root;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(middle->next);
        return root;
    }
};
```
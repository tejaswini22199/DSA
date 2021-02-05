```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> umap;
        ListNode* temp;
        temp=head;
        while(temp)
        {
            if(umap.find(temp)!=umap.end())
            {
                return true;   
            }
            umap[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};
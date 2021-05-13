>https://practice.geeksforgeeks.org/problems/bst-to-greater-sum-tree/1/?company[]=Amazon&company[]=Amazon&difficulty[]=1&page=1&category[]=Tree&category[]=Binary%20Search%20Tree&query=company[]Amazondifficulty[]1page1company[]Amazoncategory[]Treecategory[]Binary%20Search%20Tree#
```
class Solution
{
    public:
    void transformTreeHelper(struct Node* root,int &sum)
    {
        if(root==NULL)
        return;
        transformTreeHelper(root->right,sum);
        sum+=root->data;
        root->data=sum-root->data;
        transformTreeHelper(root->left,sum);
    }
    void transformTree(struct Node *root)
    {
        //code here
        int sum=0;
        transformTreeHelper(root,sum);
    }
};

```
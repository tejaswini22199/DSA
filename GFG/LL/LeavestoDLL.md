>https://practice.geeksforgeeks.org/problems/leaves-to-dll/1/?company[]=Amazon&company[]=Amazon&difficulty[]=1&category[]=Linked%20List&page=1&query=company[]Amazondifficulty[]1company[]Amazoncategory[]Linked%20Listpage1#
```
Node* convertToDLLHelper(Node* root,Node** head)
{
    if(root==NULL)
    return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        root->right= (*head);
        if(*head !=NULL)
            (*head)->left=root;
        *head=root;
        return NULL;
    }
    root->right=convertToDLLHelper(root->right,head);
    root->left=convertToDLLHelper(root->left,head);
    return root;
    
}
Node * convertToDLL(Node *root){
    // add code here.
    
    Node* head;
    head=NULL;
    root=convertToDLLHelper(root,&head);
    return head;
}
```
>https://practice.geeksforgeeks.org/problems/reorder-list/1/?company[]=Amazon&company[]=Amazon&difficulty[]=2&page=1&category[]=Linked%20List&query=company[]Amazondifficulty[]2page1company[]Amazoncategory[]Linked%20List#
```
void reverse(Node **head)
{
    Node* prev;
    Node* nxt;
    Node* temp;
    temp=*head;
    prev=NULL;
    
    while(temp)
    {
        nxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
    }
    *head=prev;
    
}
void reorderList(Node* head) {
    // Your code here
    Node* slow;
    Node* fast;
    slow=head;
    fast=slow->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* head2;
    head2=slow->next;
    slow->next=NULL;
    reverse(&head2);
    Node* nxt;
    Node* temp1;
    Node* temp2;
    Node* nxt2;
    temp1=head;
    temp2=head2;
    while(temp1 && temp2)
    {
        nxt=temp1->next;
        temp1->next=temp2;
        nxt2=temp2->next;
        temp2->next=nxt;
        temp1=nxt;
        temp2=nxt2;
    }
    
    
    
}
```
>https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#

```
Node* Merge(Node* a,Node* b)
{
    Node* result=NULL;
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;
    if(a->data<b->data)
    {
        a->next=Merge(a->next,b);
        return a;
        
    }
    else{
        b->next=Merge(a,b->next); 
        return b;
    }
    
    //return result;
}
Node* mergeSort(Node* head) {
    if(head==NULL || head->next==NULL)
    return head;
    Node* fast;
    Node* slow;
    slow=head;
    fast=head->next;
    while (fast && fast->next) { 
         
            slow = slow->next; 
            fast = fast->next->next; 
     
    } 
    Node* head1;
    Node* head2;
  
    head1=head;
    head2=slow->next;
    slow->next=NULL;
    // your code here
  
   
  return Merge(mergeSort(head1),mergeSort(head2));
}

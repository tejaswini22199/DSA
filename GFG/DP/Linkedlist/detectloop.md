
```
bool detectLoop(Node* head)
{
    // your code here
    Node* fast;
    Node* slow;
    fast=head;
    slow=head;
    while(fast && fast->next ){
        fast=fast->next->next;
        slow=slow->next;
    if(fast==slow){
        return true;
    }
    }
    return false;
    
}
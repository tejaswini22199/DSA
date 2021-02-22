### With STack
```
struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    
    stack<node*> st;
    int count;
    //count=0;
    struct node* prev;
    struct node* current;
    current=head;
    prev=NULL;
    while(current)
    {
        count=0;
        while(current !=NULL && count<k)
        {
            st.push(current);
            count++;
            current=current->next;
        }
        while(st.size()>0){
        if(prev==NULL)
        {
            prev=st.top();
            head=prev;
            st.pop();
        }
        else{
           
            prev->next=st.top();
            prev=prev->next;
            st.pop();
            
        }
        }
    }
    prev->next=NULL;
    return head;
}
```
### Without stack

```
struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    
    int count=0;
    struct node* prev;
    struct node* next;
    struct node* current;
    current=head;
    prev=NULL;
    while(current && count<k)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(next!=NULL)
    head->next=reverse(next,k);
    return prev;
}

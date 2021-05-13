>https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1/?company[]=Amazon&company[]=Amazon&difficulty[]=2&page=1&category[]=Linked%20List&query=company[]Amazondifficulty[]2page1company[]Amazoncategory[]Linked%20List#
```
Node *copyList(Node *head) {
    // Your code here
    Node* temp;
    temp=head;
    Node* temp1;
    Node* nxt;
    while(temp)
    {
        nxt=temp->next;
        temp->next=new Node(temp->data);
        temp->next->next=nxt;
        temp=nxt;
    }
   // print(head);
    // Node* head2;
    // head2=NULL;
    temp=head;
    while(temp)
    {
        if(temp->next)
        temp->next->arb=(temp->arb)?(temp->arb->next):(temp->arb);
        temp=(temp->next)?(temp->next->next):(temp->next);
    }
    Node* head2;
    head2=head->next;
    Node* head1;
    head1=head;
    Node* start;
    start=head2;
    while(head1 && head2)
    {
        head1->next=(head1->next)?head1->next->next:(head1->next);
        head2->next=(head2->next)?head2->next->next:(head2->next);
        head1=head1->next;
        head2=head2->next;
    }
    return start;
    
}
```
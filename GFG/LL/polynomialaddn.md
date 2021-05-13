>https://practice.geeksforgeeks.org/problems/polynomial-addition/1/?company[]=Amazon&company[]=Amazon&difficulty[]=1&category[]=Linked%20List&page=1&query=company[]Amazondifficulty[]1company[]Amazoncategory[]Linked%20Listpage1

```
class Solution{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node* addPolynomial(Node *p1, Node *p2)
    {
        //Your code here
        Node* newNode;
        Node* p3;
        Node* temp1;
        Node* temp2;
        temp1=p1;
        temp2=p2;
        newNode=new Node(0,0);
        p3=newNode;
        while(temp1 && temp2)
        {
            if(temp1->pow>temp2->pow)
            {
                newNode->pow=temp1->pow;
                newNode->coeff=temp1->coeff;
                temp1=temp1->next;
            }
            else if(temp2->pow>temp1->pow) {
                newNode->pow=temp2->pow;
                newNode->coeff=temp2->coeff;
                temp2=temp2->next;
            }
            else{
                newNode->pow=temp1->pow;
                newNode->coeff=temp1->coeff+temp2->coeff;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            
            if(temp1 || temp2)
            {
                newNode->next=new Node(0,0);
               newNode=newNode->next;
                newNode->next=NULL;   
            }
        }
        while(temp1 || temp2)
        {
            if(temp1)
            {
                newNode->pow=temp1->pow;
                newNode->coeff=temp1->coeff;
                temp1=temp1->next;
            }
            if(temp2)
            {
                newNode->pow=temp2->pow;
                newNode->coeff=temp2->coeff;
                temp2=temp2->next;
            }
            if(temp1 || temp2)
            {
                newNode->next=new Node(0,0);
               newNode=newNode->next;
                newNode->next=NULL;   
            }
            
        }
        return p3;
    }
};


// { Driver Code Starts.
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        Solution obj;
        Node *sum = obj.addPolynomial(poly1,poly2);
        for(Node* ptr=sum ; ptr ; ptr=ptr->next  )
        {
            // printing polynomial
            cout<< ptr->coeff << "x^" << ptr->pow;
            if(ptr->next) cout<<" + ";
        }
        cout<<endl;
       
    }

}
  // } Driver Code Ends
```
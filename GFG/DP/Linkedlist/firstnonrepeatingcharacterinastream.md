### Using DoubleLinkedList
```
class Solution {
    struct Node{
        char a;
        struct Node* next;
        struct Node* prev;
    };
	public:
	void appendNode(struct Node** head,struct Node** tail,char x){
	    struct Node* temp=new Node();
	    temp->a=x;
	    temp->next=NULL;
	    temp->prev=NULL;
	    if(*head==NULL)
	    {
	        *head=temp;
	        *tail=temp;
	        return;
	    }
	    (*tail)->next=temp;
	    temp->prev=(*tail);
	    *tail=temp;
	}
	void removeNode(struct Node** head,struct Node** tail,struct Node* temp){
	    if(head==NULL)
	    return;
	    if(*head==temp)
	    {
	        (*head)=(*head)->next;
	    }
	    if(*tail==temp)
	    {
	        (*tail)=(*tail)->prev;
	    }
	    if(temp->prev!=NULL)
	    temp->prev->next=temp->next;
	    if(temp->next!=NULL)
	    temp->next->prev=temp->prev;
	    delete temp;
	}
		string FirstNonRepeating(string A){
		    // Code here
		    struct Node* head;
		    struct Node* tail;
		    head=NULL;
		    tail=NULL;
		    Node* arr[26]={NULL};
		    int n=A.length();
		    string res;
		    bool repeated[26]={false};
		    for(int i=0;i<n;i++)
		    {
		        if(repeated[A[i]-'a']==false)
		        {
		            if(arr[A[i]-'a']==NULL){
		                appendNode(&head,&tail,A[i]);
		                arr[A[i]-'a']=tail;
		            }
		            else{
		                removeNode(&head,&tail,arr[A[i]-'a']);
		                arr[A[i]-'a']=NULL;
		                repeated[A[i]-'a']=true;
		                
		            }
		        }
		        if(head){
		            res+=head->a;
		        }
		        else{
		            res+='#';
		        }
		    }
		    return res;
		}

};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;

```
### Using Queue


```
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    int n=A.length();
		    int freq[26]={0};
		    string res;
		    for(int i=0;i<n;i++)
		    {
		       // cout<<"1"<<endl;
                q.push(A[i]);
                freq[A[i]-'a']++;
                while(!q.empty()){
                   // cout<<"whileloop"<<endl;
                    if(freq[q.front()-'a']>1){
                        q.pop();
                    }
                    else{
                        res+=q.front();
                        break;
                    }
                }
                if(q.empty()){
                    res+='#';
                }
		    }
		    return res;
		}

};
```
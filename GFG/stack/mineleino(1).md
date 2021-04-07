>https://practice.geeksforgeeks.org/problems/special-stack/1#

```
int min_e;
void push(stack<int>& s, int a){
	// Your code goes here
// 	if(s.size())
// 	return;
	if(isEmpty(s))
	{
	    min_e=a;
	    s.push(a);
	    return;
	}
	else{
	    if(a<min_e)
	    {
	        int x=min_e;
	        min_e=a;
	        s.push(2*a-x);
	    }
	    else
	    {
	        s.push(a);
	    }
	}
    
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size()==n)
	return true;
	return false;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.size()==0)
	return true;
	return false;
}

int pop(stack<int>& s){
	// Your code goes here
	if(isEmpty(s))
	return -1;
	if(s.top()>=min_e)
	{
	    int x=s.top();
	    s.pop();
	    return x;
	}
	else{
	    int x=min_e;
	    min_e=2*min_e-s.top();
	     s.pop();
	    return x;
	}
}

int getMin(stack<int>& s){
	// Your code goes here
	return min_e;
}
```
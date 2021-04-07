>https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0#
```
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++)
    	cin>>arr[i];
    	int k;
    	cin>>k;
    	vector<int> res;
    	int i=0;
    	int j=0;
    	list<int> l;
    	while(j<n)
    	{
    	    if(arr[j]<0)
    	    l.push_back(arr[j]);
    	    if(j-i+1!=k)
    	    {
    	        
    	        j++;
    	        
    	    }
    	    else{
    	         res.push_back(l.front());
    	        if(arr[i]<0)
    	        l.pop_front();
    	       // if(arr[j]<0)
    	       // l.push_back(arr[j]);
    	      
    	        i++;
    	        j++;
    	    }
    	    
    	    
    	}
    	for(int i=0;i<res.size();i++)
    	cout<<res[i]<<" ";
    	cout<<endl;
	}
	
	return 0;
}
```
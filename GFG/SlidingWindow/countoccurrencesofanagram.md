>https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1#
```
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    map<char,int> m;
	    int k=pat.length();
	    int n=txt.length();
	    for(int i=0;i<k;i++)
	    m[pat[i]]++;
	    int count=m.size();
	    int i,j;
	    i=0;
	    j=0;
	    int ans=0;
	   // f--0
	   // o--0
	   // r--0
	   // count=0
	    while(j<n)
	    {
	        if(j-i+1==k)
	        {
	             m[txt[j]]--;
	            if(m[txt[j]]==0)
	            count--;
	            if(count==0)
	            ans++;
	            if(m[txt[i]]==0)
	            count++;
	            m[txt[i]]++;
	            
	            i++;
	            j++;
	        }
	        else{
	            m[txt[j]]--;
	            if(m[txt[j]]==0)
	            count--;
	            j++;
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
```
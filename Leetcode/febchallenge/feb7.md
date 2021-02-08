
```
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        int prev=INT_MIN/2;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
            {
                prev=i;
            }
            arr[i]=i-prev;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==c)
            {
                prev=i;
            }
            arr[i]=min(arr[i],abs(prev-i));
        }
        return arr;
    }
};
```

```
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
                res[i]=0;
            else
                res[i]=n;
        }
        for(int i=1;i<n;i++)
        {
            res[i]=min(res[i],res[i-1]+1);
        }
        for(int i=n-2;i>=0;i--)
        {
            res[i]=min(res[i],res[i+1]+1);
        }
        return res;
    }
};
```
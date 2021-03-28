>https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/?company[]=Amazon&company[]=Amazon&problemStatus=unsolved&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolveddifficulty[]1page1company[]Amazon#
```
class Solution
{
    public:
    void AllParenthesisHelper(int n,int open,int close,vector<string> &res,string & path)
    {
        if(close==n)
        {
            res.push_back(path);
            
            return;
        }
        if(open>close)
        {
            path.push_back(')');
            AllParenthesisHelper(n,open,close+1,res,path);
            path.pop_back();
        }
        if(open<n)
        {
            path.push_back('(');
            AllParenthesisHelper(n,open+1,close,res,path);
            path.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
       vector<string> res;
       string path="";
       AllParenthesisHelper(n,0,0,res,path);
       return res;
    }
};

```
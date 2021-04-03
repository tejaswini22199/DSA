>https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1/?company[]=Amazon&amp;company[]=Amazon&amp;difficulty[]=2&amp;page=1&amp;category[]=Dynamic%20Programming&amp;query=company[]Amazondifficulty[]2page1company[]Amazoncategory[]Dynamic%20Programming#
```
class Solution {
  public:
    bool isPalindrome(string S,int low,int high)
    {
        while(low<high)
        {
            if(S[low]!=S[high])
            return false;
            low++;
            high--;
        }
        return true;
    }
    void getGrayHelper(string S,int start,int n,vector<vector<string>> &res,vector<string> &path)
    {
        if(start==n)
        {
            res.push_back(path);
            return;
        }
        for(int i=start;i<n;i++)
        {
        if(isPalindrome(S,start,i))
        {
            path.push_back(S.substr(start,i-start+1));
            getGrayHelper(S,i+1,n,res,path);
            path.pop_back();
        }
        }
    }
    vector<vector<string>> getGray(string S) {
        // code here
        vector<string> path;
        vector<vector<string>> res;
        int n=S.length();
        getGrayHelper(S,0,n,res,path);
        return res;
    }
};
```
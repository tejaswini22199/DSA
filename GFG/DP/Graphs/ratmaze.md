>https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
```
class Solution{
    public:
    bool isValid(int a,int b,int m,int n){
        if(a<0||b<0||a>=m||b>=n)
        return false;
        else
        return true;
    }
    void dfs(vector<vector<int>> &m,int n,vector<string> & result,string & temp,int r,int c)
    {
        if(m[r][c]==0)
        return;
        
        if(r==n-1 && c==n-1)
        {
            result.push_back(temp);
           // temp="";
            return;
        }
        m[r][c]=0;
        if(isValid(r+1,c,n,n) )
        {
           // m[r+1][c]=0;
            temp+='D';
            dfs(m,n,result,temp,r+1,c);
            temp.pop_back();
            // m[r+1][c]=1;
        }
         if(isValid(r,c+1,n,n) )
        {
           // m[r][c+1]=0;
            temp+='R';
            dfs(m,n,result,temp,r,c+1);
            temp.pop_back();
          //  m[r][c+1]=1;
        }
         if(isValid(r-1,c,n,n) )
        {
            temp+='U';
           // m[r-1][c]=0;
            dfs(m,n,result,temp,r-1,c);
            temp.pop_back();
            //m[r-1][c]=1;
        }
         if(isValid(r,c-1,n,n) )
        {
           // m[r][c-1]=0;
            temp.push_back('L');
            dfs(m,n,result,temp,r,c-1);
            temp.pop_back();
           // m[r][c-1]=1;
        }
        m[r][c]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        string temp;
        dfs(m,n,res,temp,0,0);
        sort(res.begin(),res.end());
        return res;
    }
};

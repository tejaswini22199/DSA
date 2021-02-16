>https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&difficulty[]=2&page=1&query=category[]Dynamic%20Programmingdifficulty[]2page1category[]Dynamic%20Programming#

```
class Solution{
     //int res=0;
    public:
    bool isValid(int row,int col,int m,int n)
    {
        if(row>=m || col>=n||row<0 || col<0)
        {
            return false;
        }
        return true;
    }
    int dfs(int row,int col,int source,string target,vector<vector<char>> mat)
    {
        char x=mat[row][col];
        int m=mat.size();
        int n=mat[0].size();
        if(source>=target.length())
        return 0;
        if(mat[row][col]!=target[source])
        return 0;
        int res=0;
        if(source==target.length()-1)
        return 1;
        mat[row][col]='\0';
        if(isValid(row+1,col,m,n))
            res+=dfs(row+1,col,source+1,target,mat);
        if(isValid(row,col+1,m,n))
            res+=dfs(row,col+1,source+1,target,mat);
        if(isValid(row-1,col,m,n))
            res+=dfs(row-1,col,source+1,target,mat);
        if(isValid(row,col-1,m,n))
            res+=dfs(row,col-1,source+1,target,mat);
        mat[row][col]=x;
        return res;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int i,j;
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
       
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
             
                if(mat[i][j]==target[0])
                {
                   ans+= dfs(i,j,0,target,mat);
                }
            }
        }
        return ans;
    }
};
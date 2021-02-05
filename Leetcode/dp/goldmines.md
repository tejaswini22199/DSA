```
class Solution {
    int dir[5]={0,1,0,-1,0};
public:
    bool isValid(int a,int b,int m,int n)
    {
        if(a<0 || a==m || b<0 || b==n)
            return false;
        return true;
    }
    int dfs(vector<vector<int>> &grid,int r,int c)
    {
        int m=grid.size();
        int n=grid[0].size();
        int temp=grid[r][c];
        grid[r][c]=0;
        int res=0;
        for(int i=0;i<4;i++)
        {
          int a= r+dir[i];
          int b= c+dir[i+1];
          if(isValid(a,b,m,n) && grid[a][b])
          {
             res=max(res,grid[a][b]+dfs(grid,a,b)); 
          }
        }
        grid[r][c]=temp;
        return res;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int i,j;
        int n=grid.size();
        int m=grid[0].size();
        int maximumGold=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    maximumGold=max(maximumGold,grid[i][j]+dfs(grid,i,j));
                }
            }
        }
        return maximumGold;
    }
};
> https://leetcode.com/problems/range-sum-query-2d-immutable/solution/

```
class NumMatrix {
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        dp.resize(r+1,vector<int>(c+1,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]+matrix[i][j]-dp[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        ans=dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
        return ans;
    }
};
```

```
class NumMatrix {
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        dp.resize(r,vector<int>(c+1,0));
        for(int i=0;i<r;i++)
        {
            dp[i][1]=matrix[i][0];
            for(int j=2;j<=c;j++)
            {
                dp[i][j]=dp[i][j-1]+matrix[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        for(int i=row1;i<=row2;i++)
        {
            ans+=dp[i][col2+1]-dp[i][col1];
        }
        return ans;
    }
};
```
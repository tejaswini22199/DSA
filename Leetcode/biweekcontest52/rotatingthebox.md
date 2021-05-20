>https://leetcode.com/contest/biweekly-contest-52/problems/rotating-the-box/

```
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int r=box.size();
        int c=box[0].size();
        vector<vector<char>> res(c,vector<char>(r,'.'));
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1,k=c-1;j>=0;j--)
            {
                if(box[i][j]!='.')
                {
                    k=(box[i][j]=='*')?j:k;
                    res[k--][r-i-1]=box[i][j];
                }
            }
        }
        return res;
    }
};
```
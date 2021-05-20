>https://leetcode.com/contest/weekly-contest-241/problems/sum-of-all-subset-xor-totals/

```
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        //i==1 temp=0 
        //cout<<(1<<n)<<endl;
        for(int i=0;i<(1<<n);i++)
        {
            int temp;
            temp=0;
            for(int j=0;j<n;j++)
            {
                if((1<<j)&(i))
                {
                    temp=temp^nums[j];   
                }
                  
            }
          //  cout<<temp<<endl;
            res+=temp;
        }
        return res;
    }
};
```
another one todo
//https://leetcode.com/problems/sum-of-all-subset-xor-totals/discuss/1211177/Simple-trick-oror-4-lines-of-code-oror-Explained!!
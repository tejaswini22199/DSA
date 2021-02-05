```
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        map<int,int> freq_of_numbers;
        map<int,int>::iterator i;
        for(int i=0;i<n;i++)
        {
            freq_of_numbers[nums[i]]++;
        }
        int res=0;
        int ans=0;
        for(i=freq_of_numbers.begin();i!=freq_of_numbers.end();i++)
        {
           // cout<<i->first<<" "<<i->second<<endl;
           if(freq_of_numbers.find(i->first+1)!=freq_of_numbers.end())
           {
               res=freq_of_numbers[i->first]+freq_of_numbers[i->first+1];
               ans=max(res,ans);
               
               //cout<<res<<endl;
           }
        }
        return ans;
    }
};
```
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        int tot=n*(n+1)/2;
         int sum=0;
        int arr_sum=0;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            arr_sum+=nums[i];
        }
       
        for(auto it:s)
        {
            sum+=it;
        }
        int b=tot-sum;
        int a=arr_sum-sum;
        return {a,b};
    }
};
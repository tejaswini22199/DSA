>https://leetcode.com/contest/weekly-contest-240/problems/maximum-subarray-min-product/

```
lass Solution {
    int mod=1e9+7;
public:
    int maxSumMinProduct(vector<int>& nums) {
        stack<int> left;
        stack<int> right;
        int n=nums.size();
        int left_arr[n];
        int right_arr[n];
        long long int prefix[n+1];
        long long int ans=0;
        prefix[0]=0;
        for(int i=1;i<=n;i++)
            prefix[i]=prefix[i-1]+nums[i-1];
        for(int i=0;i<n;i++)
        {
            while(!left.empty() && nums[left.top()]>=nums[i])    
                left.pop();
                if(!left.empty())
                left_arr[i]=left.top();
                else
                left_arr[i]=-1;
            left.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!right.empty() && nums[right.top()]>=nums[i])
            
                right.pop();
            if(!right.empty())
                right_arr[i]=right.top();
            
            if(right.empty())
                right_arr[i]=n;
            right.push(i);
        }
        for(int i=0;i<n;i++)
        {
            ans=max(ans,nums[i]*(prefix[right_arr[i]]-prefix[left_arr[i]+1]));
        }
        return ans%mod;
    }
};
```
```
To make it simple, we will store indexes of elements, as we can get their values from the original array. Note that we remove all remaining elements from the stack when i = n.size() in the second loop.

int maxSumMinProduct(vector<int>& n) {
    long res = 0;
    vector<long> dp(n.size() + 1), st;
    for (int i = 0; i < n.size(); ++i)
       dp[i + 1] = dp[i] + n[i];
    for (int i = 0; i <= n.size(); ++i) {
        while (!st.empty() && (i == n.size() || n[st.back()] > n[i])) {
            int j = st.back();
            st.pop_back();
            res = max(res, n[j] * (dp[i] - dp[st.empty() ? 0 : st.back() + 1]));
        }
        st.push_back(i);
    }
    return res % 1000000007;
}
```
>https://leetcode.com/contest/weekly-contest-240/problems/maximum-distance-between-a-pair-of-values/

```
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i,j;
        int m=nums1.size();
        int n=nums2.size();
        int ans=0;
        i=0;
        j=0;
        while(i<m && j<n)
        {
            if(nums1[i]>nums2[j])
                i++;
            else
                ans=max(ans,j++ -i);
        }
        return ans;
    }
};

```


```
class Solution {
public:
    int lowerBound(vector<int>& nums1, int si, int ei, int el) {
        int idx = nums1.size();
        while (si >= ei) {
            int mid = (si + ei) / 2;
            if (nums1[mid] <= el) {
                idx = mid;
                si = mid - 1;
            } else {
                ei = mid + 1;
            }
        }
        
        return idx;
    }
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // if ()
        int ans = 0;
        int n = nums2.size();
        
        for (int j = 0; j < n; j++) {
            int idx = lowerBound(nums1, nums1.size() - 1, 0, nums2[j]);
            if (idx <= j && idx != nums1.size()) {
                ans = max(ans, j - idx);
            }
        }
        
        return ans;
    }
};
```
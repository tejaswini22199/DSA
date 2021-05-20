>https://leetcode.com/contest/weekly-contest-241/problems/finding-pairs-with-a-certain-sum/

```
class FindSumPairs {
    vector<int> arr1,arr2;
    unordered_map<int,int> map2;
    
   
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        int n2;
      
        n2=nums2.size();
        arr2=nums2;
        for(int i=0;i<n2;i++)
        {
            map2[arr2[i]]++;  
        }
        arr1=nums1;
    }   
    void add(int index, int val) {
	//remove element count from map
        map2[arr2[index]]--;
		//modify in arr2 with new value
        arr2[index]+=val;
		//inc count for new value in map
        map2[arr2[index]]++;
    }
    int count(int tot) {
        int ans=0;
		//finding relevant pairs
        for(auto it:arr1)
        {
            if(map2.find(tot-it)!=map2.end())
                ans=ans+map2[tot-it];    
        }
        return ans;
        
    }
};

```
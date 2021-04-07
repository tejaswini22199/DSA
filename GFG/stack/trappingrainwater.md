>https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
```
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int mxL[n];
        int mxR[n];
        mxL[0]=arr[0];
        mxR[n-1]=arr[n-1];
        for(int i=1;i<n;i++)
        mxL[i]=max(mxL[i-1],arr[i]);
        for(int i=n-2;i>=0;i--)
        mxR[i]=max(mxR[i+1],arr[i]);
        int res=0;
        for(int i=0;i<n;i++)
            res+=min(mxL[i],mxR[i])-arr[i];
        return res;
    }
};
```
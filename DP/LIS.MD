* LIS O(NLOG(N))
```
#include<bits/stdc++.h>
using namespace std;
int longestSubsequence(int n, int a[])
    {
       // your code here
       if(n==0)
       return 0;
       vector<int> subseq(n,0);
       subseq[0]=a[0];
       int length=1;
       for(int i=1;i<n;i++)
       {
         auto begin=subseq.begin();
         auto end=subseq.begin()+length;
           auto it=lower_bound(begin,end,a[i]);
          // cout<<*it<<endl;
           if(it==end){
           subseq[length++]=a[i];
           //cout<<a[i]<<","<<length<<endl;
           //cout<<length<<endl;
           }
           else
           {
               int p=it-subseq.begin();
             //  cout<<i<<","<<p<<endl;
              // cout<<p<<endl;
               subseq[p]=a[i];
           }
           //subseq[]=a[i];
       }
       return length;
    }
    int main()
    {
      int arr[16]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
      int n=sizeof(arr)/sizeof(arr[0]);
      cout<<longestSubsequence(n,arr)<<endl;
    }
```
* DP

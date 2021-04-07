>https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1#
```
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i,j;
        i=0;
        j=0;
        int max_sum=0;
        int cont_sum=0;
        while(j<N)
        {
            if(j-i+1==K)
            {
                cont_sum+=Arr[j];
                max_sum=max(max_sum,cont_sum);
                cont_sum-=Arr[i];
                i++;
                j++;
            }
            else{
                 cont_sum+=Arr[j];
                  j++;
            }
        }
        return max_sum;
    }
};

```
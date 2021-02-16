Find the number of unique words consisting of lowercase alphabets only of length N that can be formed with at-most K contiguous vowels. 

Example 1:

Input:
N = 1
K = 0
Output:
21
Explanation:
All 21 consonants.
 

Example 2:

Input:
N = 1
K = 1
Output:
26
Explanation:
All the english alphabets including
vowels and consonants.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function kvowelwords() which takes an Integer N, an intege K and returns the total number of words of size N with atmost K vowels. As the answer maybe to large please return answer%1000000007.

Expected Time Complexity: O(N*K)
Expected Auxiliary Space: O(N*K)

 

Constraints:
1 ≤ N ≤ 1000
1 ≤ K ≤ N



```
class Solution
{
public:
long long int power(long long int x, long long int y, long long int p)  
        {  
        long long int res = 1ll;     
  
         x = x % p;   
               
        if (x == 0) return 0; 
  
         while (y > 0)  
            {  
        
              if (y & 1)  
                res = (res*x) % p;  
            y = y>>1; 
           x = (x*x) % p;  
            }  
    return res;  
}  
    int kvowelwords(int N,int K)
    {
        long long int mod=1000000007;
        long long int dp[N+1][K+1]={0};
        long long int i,j,sum;
        sum=1;
        for(i=1;i<=N;i++)
        {
            dp[i][0]=sum*21;
            dp[i][0]%=mod;
            sum=dp[i][0];
            for(j=1;j<=K;j++)
            {
                if(j>i)
                     dp[i][j]=0;
                else if(j==i)
                {
                    dp[i][j]=power(5,i,mod);
                }
                else{
                    dp[i][j]=dp[i-1][j-1]*5ll;
                }
                dp[i][j]%=mod;
                sum+=dp[i][j];
                sum%=mod;
                
            }
        }
        return sum;


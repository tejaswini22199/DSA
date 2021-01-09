## mcm variation
##### boolean parenthesis
```
using namespace std;
#define mod 1003
void booleanParenthesization(string s , int n){
	//vector<vector<int> > dp(n,vector<int>(n,0));
	int dp[n][n][2];

	for(int i=n-1;i>=0;i=i-2){
		for(int j=i;j<n;j=j+2){
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;

			if(i==j){
				if( s[i] == 'T'){			
					dp[i][j][0] = 1;
					dp[i][j][1] = 0;
				}
				else if (s[i] == 'F'){
					dp[i][j][0] = 0;
					dp[i][j][1] = 1;
				}
			}
			else{
				for(int k=i+1;k<j;k=k+2){
					if(s[k] == '&'){
						dp[i][j][0] +=   dp[i][k-1][0]*dp[k+1][j][0];
						dp[i][j][1] +=   dp[i][k-1][1]*dp[k+1][j][1] +  dp[i][k-1][1]*dp[k+1][j][0] + dp[i][k-1][0]*dp[k+1][j][1];
					}
					else if(s[k]=='|'){	
						dp[i][j][0] += dp[i][k-1][0]*dp[k+1][j][0] +  dp[i][k-1][1]*dp[k+1][j][0] + dp[i][k-1][0]*dp[k+1][j][1];
						dp[i][j][1] += dp[i][k-1][1]*dp[k+1][j][1];
					}
					else if(s[k]=='^'){		
						dp[i][j][0] +=   dp[i][k-1][0]*dp[k+1][j][1] + dp[i][k-1][1]*dp[k+1][j][0] ;
						dp[i][j][1] +=   dp[i][k-1][0]*dp[k+1][j][0] + dp[i][k-1][1]*dp[k+1][j][1] ;
					}
				}
			}
			dp[i][j][0] = dp[i][j][0]%mod;
			dp[i][j][1] = dp[i][j][1]%mod;	
		}
	}
	cout<<dp[0][n-1][0]<<endl;

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++)
	// 		cout<<dp[i][j][0]<<" ";
	// 	cout<<endl;
	// }

}
int main(){
	int t, n ;
	cin>>t;
	while(t--){
		string s ;
		cin>>n;
		cin>>s;
		booleanParenthesization(s,n);
	}
	return 0;
}
```

### 2dDP

1. Knapsack (normal) in gfg
#### Question:
> You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

* Example 1:

> Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

* Example 2:

> Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0
Your Task:
Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[] and number of items n as a parameter and returns the maximum possible value you can get.

> Expected Time Complexity: O(N*W).
> Expected Auxiliary Space: O(N*W)
```
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   int dp[W+1][n+1];
   for(int i=0;i<=W;i++)
   dp[i][0]=0;
   for(int j=0;j<=n;j++)
   dp[0][j]=0;
   for(int i=1;i<=W;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(i==0||j==0)
           dp[i][j]=0;
           else if(wt[j-1]<=i)
           {
               dp[i][j]=max(dp[i][j-1],dp[i-wt[j-1]][j-1]+val[j-1]);
           }
           else
           dp[i][j]=dp[i][j-1];
       }
   }
   return dp[W][n];
}


```

2.  Knapsack (spoj)
* Question:
> You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.

>You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.

>You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?

>Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.

>Input
The first line of the input specifies your party budget and the number n of parties.

>The following n lines contain two numbers each. The first number indicates the entrance fee of each party. Parties cost between 5 and 25 francs. The second number indicates the amount of fun of each party, given as an integer number ranging from 0 to 10.

>The budget will not exceed 500 and there will be at most 100 parties. All numbers are separated by a single space.

>There are many test cases. Input ends with 0 0.

>Output
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space.
* Solution:

```
```


3. https://www.spoj.com/problems/MISERMAN/
> Jack is a wise and miser man. Always tries to save his money.

> One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:

>At every city, he has to change the bus.
And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.

>N, M, K <= 100.

>Input
Line 1:    N M
Line 2-:    NxM Grid

>Each row lists the fares the M busses to go form the current city to the next city.

>Output
Single Line containing the minimum amount of fare that Jack has to give.
	```
	#include<bits/stdc++.h>
using namespace std;

int save[105][105];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&save[i][j]);
	int res[n][m];
	for(i=0;i<m;i++)
		res[0][i]=save[0][i];
	for(i=1;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int l,u,r;
			l=(j>0)?(res[i-1][j-1]):INT_MAX;
			u=res[i-1][j];
			r=(j<m-1)?res[i-1][j+1]:INT_MAX;
			res[i][j]=save[i][j]+min(u,min(l,r));
		}
	}
	int ans=INT_MAX;
	for(i=0;i<m;i++)
		if(res[n-1][i]<ans)
			ans=res[n-1][i];
	printf("%d",ans);
	return 0;
}
```
* Conditions : There are n teams and at the end all teams should ahave same score. And we need to find minimum ties for this condition to satisfy.
* There are n teams and when they win winning team-->+3 losing team-->0 when it's tie--> both teams-->+1;


> https://codeforces.com/contest/1487/problem/C



```
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
     int t;
     cin>>t;
     while(t--)
     {
         int n;
         cin>>n;
         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
         vector<bool> visited(n+1,false);
         int d;
         d=1;
         while(d<(n+1)/2){
         for(int i=1;i<=n;i++)
            visited[i]=false;
         for(int i=1;i<=n;i++)
         {
             if(!visited[i])
             {
                 
                 int l,h;
                 l=i;
                 h=i+d;
                 while(!visited[l]){
                     visited[l]=true;
                 if(l<h)
                 {
                     dp[l][h]=1;
                 }
                 else
                 {
                     dp[h][l]=-1;
                 }
                 l=h;
                 h=h+d;
                 if(h>n)
                 h=(h)%n;
                 if(l>n)
                 l=(l)%n;
                 }
             }
         }
         d++;
     }
     
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            std::cout << dp[i][j] << " ";
        }
       // cout<<"\n";
    }
    cout<<endl;
     }
    return 0;
}

> Thanks to this tutorial https://youtu.be/oLhgbooPG1w
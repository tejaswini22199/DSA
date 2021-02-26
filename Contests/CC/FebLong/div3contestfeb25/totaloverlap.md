>https://www.codechef.com/CCRC21C/problems/TOVERLP
```/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
         int n,m;
         cin>>n>>m;
         vector<pair<long long int,long long int>> A(n),B(m);
         vector<pair<long long int,long long int>> points;
         for(int i=0;i<n;i++){
            cin>>A[i].first>>A[i].second;
            points.push_back({A[i].first,1});
            points.push_back({A[i].second,2});
         }
         for(int i=0;i<m;i++)
         {
             cin>>B[i].first>>B[i].second;
             points.push_back({B[i].first,3});
             points.push_back({B[i].second,4});
         }
        sort(points.begin(),points.end());
        long long int prev=0;
        long long int i=0;
        long long int a=0;
        long long int b=0;
        long long int res=0;
        while(i<2*n+2*m){
           long long x= points[i].first;
           res+=(x-prev)*a*b;
           while(i<2*n+2*m && x==points[i].first ){
               int p=points[i].second;
               if(p==1){
                   a++;
               }
               else if(p==2){
                   a--;
               }
               else if(p==3)
               {
                   b++;
               }
               else{
                   b--;
               }
               i++;
           }
            prev=x;
        }
             
       cout<<res<<endl;
    }
   

    return 0;
}

```
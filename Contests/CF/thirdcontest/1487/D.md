> https://codeforces.com/contest/1487/problem/D

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
         int a,b,c;
         a=3;
         int res=0;
         while(((a*a)+1)<=n*2)
         {
            int c=((a*a)+1)/2;
            int b=c-1;
            if(a<=b && b<=c && c<=n)
            res++;
            a+=2;
         }
         cout<<res<<endl;
     }
    return 0;
}


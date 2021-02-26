> https://www.codechef.com/CCRC21C/problems/CHEFPAT
```
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	   int n;
	   cin>>n;
	   vector<int> res(n);
	   vector<pair<int,int>> v;
	   for(int i=0;i<n;i++)
	   {
	       int x;
	       cin>>x;
	       v.push_back({x,i});
	   }
	   sort(v.begin(),v.end(),[&](const pair<int,int> p1,const pair<int,int> p2){
	       if(p1.first>p2.first)
	       return true;
	       else if(p1.first==p2.first)
	       {
	           return (p1.second>=p2.second)?false:true;
	       }
	       else
	       return false;
	   });
	   //for(int i=0;i<n;i++)
	   //cout<<v[i].second;
	   int count=1;
	   for(int i=0;i<n;i++)
	   {
	       res[v[i].second]=count;
	       count++;
	   }
	   for(int i=0;i<n;i++)
	   cout<<res[i]<<" ";
	   cout<<endl;
	   
	}
	return 0;
}
```
https://www.codechef.com/OCL2021/problems/OCLESC
```
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n;
    
    cin>>n;
    string a;
    cin>>a;
    ll ans = 0,b = 0;
    for (ll i = 0;i<n-1;i++)
        if(a[i] == 'X') b ++;
        else if(a[i] == 'Y' && a[i+1] == 'Z') ans = ans+b,i++;
        else b = 0;
        cout<<ans<<endl;
	return 0;
}

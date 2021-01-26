/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        if(n%2!=0)
        {
             cout<<"YES"<<endl;
             continue;
        }
        else
        {
            while(n%2==0 && n>1)
            {
                n=n/2;
            }
            if(n==1)
            cout<<"NO"<<endl;
            else
            cout<<"YES"<<endl;
        }
       
    }

    return 0;
}

//Editorial
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  ll n;
  cin >> n;
  if (n & (n - 1)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

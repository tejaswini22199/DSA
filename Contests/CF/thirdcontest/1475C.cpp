/******************************************************************************

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
        int a,b,k;
        cin>>a>>b>>k;
        int girls[k];
        int boys[k];
        long long int res=0;
        unordered_map<int,int> mp_g;
        unordered_map<int,int> mp_b;
        for(int i=0;i<k;i++)
        {
            cin>>girls[i];
            mp_g[girls[i]]++;
        }
        for(int i=0;i<k;i++)
        {
            cin>>boys[i];
            mp_b[boys[i]]++;
        }
        for(int i=0;i<k;i++)
        {
            res+=k-mp_g[girls[i]]-mp_b[boys[i]]+1;
        }
        cout<<res/2<<endl;
    }

    return 0;
}


```
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int s;
        cin>>s;
        int arr[s];
        long long sum=0;
        for(int i=0; i<s; i++)
            cin>>arr[i];
        int loop=0;
        while(loop<s)
        {
            int num;
            cin>>num;
            for(int i=0; i<num; i++)
            {
                int tmp;
                cin>>tmp;
                if(i==0)
                    sum+=tmp;
                else
                    sum+=tmp-arr[loop];
            }
            loop++;
        }
    cout<<sum<<endl;
    }

}

>https://www.codechef.com/FEB21C/problems/HDIVISR
```
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int res=1;
    for(int i=1;i<=10;i++)
    {
        if((N%i)==0)
        {
            res=max(res,i);
        }
    }
    cout<<res<<endl;
    return 0;
}

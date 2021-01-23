https://codeforces.com/problemset/problem/1291/A 
```
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int
main ()
{
  int t;
  cin >> t;
  while (t--)
    {
      int n;
      cin >> n;
      string s;
      cin >> s;
      int odd=0;
      int count=0;
      for (int i = 0; i < n; i++)
	{
            if((s[i]-'0')&1)
            odd++;
	}
	if(odd<=1){
	cout<<"-1"<<endl;
	continue;
    }
    for(int i=0;i<n;i++)
    {
        if((s[i]-'0')&1)
        {
            cout<<s[i];
            count++;
        }
        if(count==2)
        break;
    }
    cout<<endl;
    }
  return 0;
}

```
https://codeforces.com/problemset/problem/1375/B 
https://codeforces.com/problemset/problem/1294/C 
https://codeforces.com/problemset/problem/1285/B (Kadane’s Algo pre-req)
https://codeforces.com/problemset/problem/1201/B 
https://codeforces.com/problemset/problem/274/A 
https://codeforces.com/problemset/problem/413/C 
https://codeforces.com/problemset/problem/1368/B 
https://codeforces.com/problemset/problem/1291/B  

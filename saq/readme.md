https://www.hackerrank.com/challenges/balanced-brackets/problem 
```
#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
int n=s.length();
stack<char> st;
for(int i=0;i<n;i++)
{
    if(s[i]=='('||s[i]=='{'||s[i]=='[')
        st.push(s[i]);
    else if(s[i]==')' && (!st.empty() && st.top()!='(')||(st.empty()))
    return "NO";
    else if(s[i]=='}' && (!st.empty() && st.top()!='{')||(st.empty()))
    return "NO";
    else if(s[i]==']' && (!st.empty() && st.top()!='[')||(st.empty()))
    return "NO";
    else
    st.pop();
}
if(st.empty())
return "YES";
else
return "NO";


}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
   

    for (int i = 0; i < t; i++) {
        string s;
      cin>>s;

        string result = isBalanced(s);

        cout << result << "\n";
    }

   // fout.close();

    return 0;
}

```

https://www.codechef.com/status/THESA 
https://www.spoj.com/problems/ANARC09A/ 
```
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
int balanced(string s)
{
    int n=s.length();
    stack<char> st;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='{')
        st.push(s[i]);
        else if(!st.empty() && st.top()=='{')
        {
            st.pop();
        }
        else
        {
            st.push('{');
            ans++;
        }
    }
    ans+=st.size()/2;
    return ans;
}
int main()
{
	int i=1;
    while(true)
    {
        string s;
        cin>>s;
        
        if(s.find('-')!=string::npos)
        return 0;
        else
        cout<<i++<<". "<<balanced(s)<<endl;
    }
    
    return 0;
}

```
https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/monk-and-power-of-time-3a648bf0/ 
https://www.hackerearth.com/challenges/competitive/code-monk-heaps-and-priority-queues-1/algorithm/little-monk-and-williamson/ 
https://codeforces.com/contest/5/problem/C 

> https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-shino-and-pairs/ 

```
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> Arr(n);
	int ans=0;//3
	for(int i=0;i<n;i++)
	{
		cin>>Arr[i];
	}
	stack<int> s;
	s.push(Arr[0]); //2 5 1 3 //5 3
	for(int i=1;i<n;i++){
		while(!s.empty() && Arr[i]>s.top())
		{
			s.pop();
			ans++;
		}
		if(!s.empty())
		{
			ans++;
		}
		s.push(Arr[i]);
	}
	cout<<ans<<endl;
}
```
> https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/seating-arrangement-6b8562ad/ 

```
#include<bits/stdc++.h>
using namespace std;
int main()
{
	unordered_map<long long int, long long int>m;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long int N,K,start,mid,end,size;
	cin>>N>>K;
	string s;
	cin>>s;
	priority_queue<pair<long long int,long long int>> pq;
	pq.push({N,-1});//5 1
	//vector<long long int> v(N+1,-1);//3--1
	for(int i=1;i<=K;i++)
	{
		pair<long long int,long long int> t;
		t=pq.top();
		pq.pop();
		start=-t.second;//1
		size=t.first;
		end=start+size-1;//5
		mid=(start+end)/2;//3
		if(size%2==1)
		{
			m[mid]=i;
		}
		else
		{
			if(s[i-1]=='R')
			mid++;
			m[mid]=i;
		}
		pq.push({mid-start,-start}); //2 1
		pq.push({end-mid,-(mid+1)});//2 4
	}
	long long int query;
	cin>>query;
	for(long long int i=0;i<query;i++)
	{
		long long int x;
		cin>>x;
		if(m[x]>0)
		cout<<m[x]<<endl;
		else
		cout<<"-1"<<endl;
	}
}
```
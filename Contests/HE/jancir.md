1. https://www.hackerearth.com/problem/algorithm/gcd-function-9fe49c14/description/
```
#include<bits/stdc++.h>
using namespace std;
long long int lcm(long long int a,long long int b)
{
	return (a*b)/__gcd(a,b);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int sum=0;
		sum=(n*(n+1))/2;
		long long int res_lcm=1;
		for(int i=2;i<=n;i++)
		{
			res_lcm=lcm(res_lcm,i);
		}
		cout<<sum<<" "<<res_lcm<<" "<<endl;
	}
}

```
2.  https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/make-them-equal-too-89585e71/description/


```
```

3. https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/chessboard-2-8f06e380/

```
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2 && y1==y2)
		cout<<"SECOND"<<endl;
		else if(abs(x1-x2)<=1 && abs(y1-y2)<=1)
		cout<<"FIRST"<<endl;
		else
		cout<<"DRAW"<<endl;

	}
}
```
> There are only 3 cases if both co-ordinates are equal second king wins
> If the distance between first and second king is 1 then it is first
> Else both play optimally so draw.

4. https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/approximate/kolmogorov-78780f09/description/

```
https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/approximate/kolmogorov-78780f09/editorial/

```

5. https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/make-them-equal-ac0bab4a/
```

// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		int freq1[26];
		int freq2[26];
		int index1,index2;
		memset(freq1,0,sizeof(freq1));
		memset(freq2,0,sizeof(freq2));
		for(int i=0;i<n;i++)
		{
			if(a[i]!='?')
			freq1[a[i]-'a']++;
			if(b[i]!='?')
			freq2[b[i]-'a']++;
			if(a[i]=='?')
			index1=i;
			if(b[i]=='?')
			index2=i;
		}
		int count=0;
		for(int i=0;i<26;i++)
		{
			if(count==2)
			break;
			if(freq1[i]<freq2[i])
			{
				a[index1]=i+'a';
				freq1[i]++;
				count++;
			}
			if(freq2[i]<freq1[i])
			{
				b[index2]=i+'a';
				freq2[i]++;
				count++;
			}
		}
		int i;
		for(i=0;i<26;i++)
		{
			if(freq1[i]!=freq2[i])
			{
				cout<<"NO"<<endl;
				break;
			}
		}
		if(i==26)
		cout<<"YES"<<endl;
	}
}
t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    s = input()
    l1 = [s.count(chr(i)) for i in range(ord('a'), ord('z') + 1)]
    s = input()
    l2 = [s.count(chr(i)) for i in range(ord('a'), ord('z') + 1)]
    print("YES" if sum(abs(x - y) for x, y in zip(l1, l2)) <= 2 else "NO")
```

6. https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/approximate/tree-construction-7b3cb288/description/

```
```

7. https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/tree-game-2-e6796bef/


```
```

8. https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/tournament-and-ranks-67cd4b7e/


```
```
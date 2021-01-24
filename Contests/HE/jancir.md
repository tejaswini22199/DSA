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

4. https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/make-them-equal-too-89585e71/description/
```
#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int temp[],int l,int mid,int h)
{
	 int i=l;
	 int j=mid;
	 int k=l;
	 int res=0;
	 while(i<=mid-1 && j<=h)
	 {
		 if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
			res+=mid-i;
		}
	 }
	 while(i<=mid-1)
	 {
		 temp[k++]=arr[i++];
	 }
	 while(j<=h)
	 {
		 temp[k++]=arr[j++];
	 }
	 for(int i=l;i<=h;i++)
	 arr[i]=temp[i];
	 return res;
}
int _mergeSort(int arr[],int temp[],int l,int h)
{
	int inv_count=0;
	if(l<h)
	{
		int mid=(l+h)/2;
		inv_count=_mergeSort(arr,temp,l,mid);
		inv_count+=_mergeSort(arr,temp,mid+1,h);
		inv_count+=merge(arr,temp,l,mid+1,h);
	}
	return inv_count;
}
int _mergeSort_Helper(int arr[],int n)
{
	int temp[n];
	return _mergeSort(arr,temp,0,n-1);
}

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
		int freq[26];
		memset(freq,0,sizeof(freq));
		int i;
		for(i=0;i<n;i++)
		{
			freq[a[i]-'a']++;
			if(freq[a[i]-'a']>1)
			break;
		}
		//cout<<i<<endl;
		if(i==n)
		{
			int arr[n];
			int brr[n];
			for(int i=0;i<n;i++)
			{
				arr[i]=(int)a[i];
				brr[i]=(int)b[i];
			}
			int x=_mergeSort_Helper(arr,n);
			int y=_mergeSort_Helper(brr,n);
			if((abs(x-y))%2==0)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}	
		else
		{
			sort(a.begin(),a.end());
			sort(b.begin(),b.end());
			if(a==b)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
	}
}

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
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		int arr[n];
		int ans=0;
		unordered_map<int,int> mp;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			mp[arr[i]]++;
			if(mp[arr[i]]==1)
			ans++;
		}
		
		for(int i=0;i<q;i++)
		{
			int l,r;
			cin>>l>>r;
			l--;
			mp[arr[l]]--;
			if(mp[arr[l]]==0)
			ans--;
			arr[l]=r;
			mp[arr[l]]++;
			if(mp[arr[l]]==1)
			ans++;
			cout<<ans+1<<endl;
		}
	}
}
```
#### Question 
`https://codeforces.com/problemset/problem/271/D`
#### Using Trie
```

#include <iostream>

using namespace std;
struct Node
{
    Node* child[26];
    
};
int isbad(char x,string s1)
{
    if(s1[x-'a']=='0')
    return true;
    else
    return false;
}
int main()
{
    string s;
    cin>>s;
    string s1;
    cin>>s1;
    int k,count,res,n;
    n=s.length();
    res=0;
    cin>>k;
    Node* head=new Node();
    for(int i=0;i<n;i++)
    {
        count=0;
         Node* p;
    p=head;
        for(int j=i;j<n;j++)
        {
            if(isbad(s[j],s1))
            count++;
            if(count>k)
            break;
            if(p->child[s[j]-'a']==NULL)
            {
                p->child[s[j]-'a']=new Node();
                res++;
            }
            p=p->child[s[j]-'a'];
        }
    }
    cout<<res<<endl;
    return 0;
}

```
#### Using Rolling Hash(Rabin Karp algo)



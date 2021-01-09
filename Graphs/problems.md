Graph Algorithms (DFS, BFS, Dijsktra, Floyd Washall, Bellman Ford, Bridges, 0-1 BFS, Bipartite, Topo-sort ...) : 
https://cses.fi/problemset/task/1192 (bfs) 
[Soln](https://cses.fi/paste/10e3db3baa8431dd15cf6b/)
https://cses.fi/problemset/task/1193 
[Soln](https://cses.fi/paste/75edee2f73dbb59f15d597/)
https://codeforces.com/problemset/problem/242/C 
```
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int max=1000000000;
    int x0,y0,x1,y1;
    cin>>x0>>y0>>x1>>y1;
    int n;
    cin>>n;
    map<pair<int,int>,bool> allow;
    map<pair<int,int>,bool> vis;
    map<pair<int,int>,int> dist;
    //memset(allow,sizeof(allow),false);
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        for(int i=y;i<=z;i++)
        allow[{x,i}]=true;
    }
    queue<pair<int,int>> q;
    q.push({x0,y0});
    vector<pair<int,int>> dir;
    dir.push_back({0,1});
    dir.push_back({0,-1});
    dir.push_back({1,0});
    dir.push_back({-1,0});
    dir.push_back({1,1});
    dir.push_back({-1,1});
    dir.push_back({1,-1});
    dir.push_back({-1,-1});
    dist[{x0,y0}]=0;
    vis[{x0,y0}]=true;
    int count=0;
    allow[{x0, y0}] = true;
    allow[{x1, y1}] = true;
    while(!q.empty())
    {
        pair<int,int> temp=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int a=temp.first+dir[i].first;
            int b=temp.second+dir[i].second;
            if(vis[{a,b}])
            continue;
            if(!allow[{a,b}])
            continue;
            
            vis[{a,b}]=true;
            if(!dist[{a,b}] && dist[{a,b}]>1+dist[{temp.first,temp.second}]){
            dist[{a,b}]=1+dist[{temp.first,temp.second}];
            q.push({a,b});
            }
        }
    }
    if(vis[{x1,y1}])
    {
        cout<<dist[{x1,y1}]<<endl;
    }
    else
    cout<<"-1"<<endl;
}

```
https://cses.fi/problemset/task/1667 
https://cses.fi/problemset/task/1669 
https://cses.fi/problemset/task/1671 (Dijsktra) 
https://codeforces.com/problemset/problem/20/C 
https://cses.fi/problemset/task/1672 (Floyd Warshall) 
https://cses.fi/problemset/task/1673 
https://cses.fi/problemset/task/1197 (Bellman Ford) 
https://cses.fi/problemset/task/1679 (topo sort) 
https://codeforces.com/problemset/problem/510/C 
https://codeforces.com/problemset/problem/59/E (tough Dijsktra) 
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737 
https://www.spoj.com/problems/SUBMERGE/ 
https://www.codechef.com/problems/REVERSE (0-1 BFS) 
https://codeforces.com/contest/1296/problem/E1 (Bipartite) 

Once you have done this, if you feel like doing more, search and do as much as you can on the algo names above.. 

credits:striver
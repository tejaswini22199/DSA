### Graphs practice

* detect cycle in directed graph
1. Using graph coloring 
2. Using Recursion stack
> 1st method
```
bool iscyclic(int source,vector<int> &visited,vector<int> adj[])
{
    if(visited[source]==2)
    return true;
    if(visited[source]==0)
    visited[source]=2;
    
    vector<int>::iterator i;
    for(auto i=adj[source].begin();i!=adj[source].end();i++)
    {
        if(visited[*i]==0 && iscyclic(*i,visited,adj))
        return true;
        else if(visited[*i]==2)
        return true;
    }
    visited[source]=1;
    return false;
}
// 0-unvisited
//1 -visited
//2-current recursion
bool isCyclic(int N, vector<int> adj[])
{
    // Your code here
    vector<int> visited(N,0);
    for(int i=0;i<N;i++)
    {
        if(iscyclic(i,visited,adj))
        return true;
    }
    return false;
}
```
> 2nd method
```
bool iscyclic(int source,vector<bool> &visited,vector<bool> & Recstk,vector<int> adj[])
{
    if(visited[source]==false)
    {
    visited[source]=true;
    Recstk[source]=true;
    vector<int>::iterator i;
    for(auto i=adj[source].begin();i!=adj[source].end();i++)
    {
        if(visited[*i]==false && iscyclic(*i,visited,Recstk,adj))
        return true;
        else if(Recstk[*i]==true)
        return true;
    }
    Recstk[source]=false;
    return false;
    }
}
bool isCyclic(int N, vector<int> adj[])
{
    // Your code here
    vector<bool> visited(N,false);
    vector<bool> Recstk(N,false);
    for(int i=0;i<N;i++)
    {
        if(iscyclic(i,visited,Recstk,adj))
        return true;
    }
    return false;
}
```


### Bipartite
* Dividing vertices into two disjoint sets such that there is an edge from one vertex of one set to other vertex in the other set. 
[Link](https://www.youtube.com/watch?v=0ACfAqs8mm0&t=9s)

 Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].


```
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> AdjacencyList(N+1);
        int n=dislikes.size();
        for(int i=0;i<n;i++)
        {
            AdjacencyList[dislikes[i][0]].push_back(dislikes[i][1]);
            AdjacencyList[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        queue<int> q;
        int colors[N+1];
        memset(colors,-1,sizeof(colors));
       // -1 -1 -1 -1
        for(int i=1;i<=N;i++)
        {
            if(colors[i]==-1)
            {
                q.push(i);//1
                colors[i]=1;  //1 0 0
                while(q.empty()==false)
                {
                    int x=q.front();//1
                    q.pop();
                    int color=colors[x];//1
                    for(int i=0;i<AdjacencyList[x].size();i++)
                    {
                        if(colors[AdjacencyList[x][i]]==color)
                            return false;
                        if(colors[AdjacencyList[x][i]]==-1){
                            q.push(AdjacencyList[x][i]);
                            colors[AdjacencyList[x][i]]=1-color;//0
                        }
                    }
                }
            }
        }
        return true;
    }
};
```

### KOSARAJU ALGO(SCC)
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
#### Theory
* Strongly connected component is a part of graph where we can reach all vertices from every vertex present in the graph. If all components are SCC then it is called as SCG. In an undirected graph an SCG is a graph where vertices in a graph are connected.
* Find number of strongly connected components
* If we reverse all edges in a SCG then it will be SCG only. A single vertex is SCC
#### Algorithm
* Perform dfs and store all vertices in a stack.
* Now reverse edges of a graph and pop each vertex from stack and perform dfs. Whenver dfs ends you get a scc.(Because we are reversing all edges here so we can't travel from one scc to other).
```
void dfs1(int V,int source,vector<int> adj[],vector<bool> &visited,stack<int> &s)
{
    visited[source]=true;
    for(int i=0;i<adj[source].size();i++)
    {
        if(!visited[adj[source][i]])  
        {
           // visited[adj[source][i]]=true;
            dfs1(V,adj[source][i],adj,visited,s);
        }
    }
    s.push(source);
}
void dfs2(int V,int source,vector<int> adj[],vector<bool> &visited)
{
    visited[source]=true;
    for(int i=0;i<adj[source].size();i++)
    {
        if(!visited[adj[source][i]])  
        {
            //visited[adj[source][i]]=true;
            dfs2(V,adj[source][i],adj,visited);
        }
    }
    
}
void reverse(vector<int> adj[],int V,vector<int> temp[])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            temp[adj[i][j]].push_back(i);
        }
    }
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    stack<int> s;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        dfs1(V,i,adj,visited,s);
    }
    for(int i=0;i<V;i++)
    visited[i]=false;
    vector<int> temp[V];
    reverse(adj,V,temp);
    int scc=0;
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        if(visited[x]==false)
        {
            dfs2(V,x,temp,visited);
            scc++;
        }
    }
    
return scc;
}
```
* Otherlinks
[Link1](https://www.youtube.com/watch?v=Rs6DXyWpWrI)
[Link2](https://www.geeksforgeeks.org/strongly-connected-components/#:~:text=A%20directed%20graph%20is%20strongly,SCCs%20in%20the%20following%20graph.)

### Dijkstra Algo(SPSP)

#### Algorithm:

* This algorithm is used to find shortest path between source vertex and all nodes.
* We take 2 sets one is unvisited and other is containing nodes which are already visited.
* We select node that is unvisited with minimum distance from source we maintain a Data Structure to store distances of all nodes from source nodes.(use a min heap)
* Now we find distance of other nodes wrt this node and update accordingly.
* We maintain a data structure to store parents and children.( To find shortest path)(array)
* Doesn't work for graphs having negative edges.
* Use Bellman ford for that.





* Otherlinks
[Link1](https://www.youtube.com/watch?v=t2d-XYuPfg0&t=1188s)
[link2](https://www.youtube.com/watch?v=Sj5Z-jaE2x0)
[Link3](https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/)
[Link4](https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/)
[Link5](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)


### bellmanford

* If we have negative edge cycle then both dijkstra and bellman won't work.
* Qn- Detect if negative edge cycle is present or not
```
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int s;
    int d;
    int wt;
};
int detectNegcycle(int v, vector<edge> & edges,vector<int> & cost,int n)
{
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x=edges[j].s;
            int y=edges[j].d;
            int wt=edges[j].wt;
            if(cost[x]!=INT_MAX && cost[x]+wt<cost[y])
            cost[y]=cost[x]+wt;
        }
    }
    for(int j=0;j<n;j++)
        {
            int s=edges[j].s;
            int d=edges[j].d;
            int wt=edges[j].wt;
            if(cost[s]!=INT_MAX && cost[s]+wt<cost[d])
            return 1;
        }
    return 0;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int v,e;
	    cin>>v>>e;
	    vector<edge> edges(e);
	    for(int i=0;i<e;i++)
	    {
	        cin>>edges[i].s;
	        cin>>edges[i].d;
	        cin>>edges[i].wt;
	    }
	    vector<int> cost(v,INT_MAX);
	    cost[0]=0;
	    cout<<detectNegcycle(v,edges,cost,e)<<endl;
	}
	return 0;
}
```
O(VE)--Time Complexity
O(E)--Space

[Link1](https://www.youtube.com/watch?v=24HziTZ8_xo)
[Link2](https://www.youtube.com/watch?v=FrLWd1tJ_Wc&t=552s)


### Floyd Warshall
(All pair shortest path finder using DP)
```
#include <iostream>
using namespace std;
int main() {
	int t; cin>>t;
	while(t--){
	    int V; cin>>V;
	    int graph[V][V]; 
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
	            cin>>graph[i][j];
	           // d[i][j]=graph[i][j];
	        } 
	    }
	    for(int k=0;k<V;k++){
	        for(int i=0;i<V;i++){
    	        for(int j=0;j<V;j++){
    	            if(graph[i][j]>graph[i][k]+graph[k][j]) graph[i][j]=graph[i][k]+graph[k][j];
    	        } 
    	    }
	    }
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
	            if(graph[i][j]==10000000) cout<<"INF"<<" ";
	            else cout<<graph[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
```


### Minimum Spanning Tree
1. Prims
2. Krushkal

* Prims:
> Approach 1:(Here for v-1 times we find min vertex and do the relaxation so O(V*E))--Time complexity
> Space--O(V)
*  Algo:
    (V) vertices and we take (V-1) edges from all the edges to form an MST.Make two sets one having visited vertices and other unvisited. Now select minimum value vertex and put in visited. Now relax other vertices which are adjacent to this.Repeat the above procedure till (v-1) edges are formed. 

* Soln:


```
int findMin(int V,int values[],vector<bool> visited)
{
    int min=INT_MAX;
    int index;
    for(int i=0;i<V;i++)
    {
        if(values[i]!=INT_MAX && values[i]<min && !visited[i])
        {
            min=values[i];
            index=i;
        }
       
    }
    return index;
}
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    
    int values[V];
    for(int i=0;i<V;i++)
    {
        values[i]=INT_MAX;
    }
    vector<bool> visited(V,false);
    int count=0;
    int sum=0;
    values[0]=0;
    while(count<V-1)
    {
        int index=findMin(V,values,visited);
        visited[index]=true;//tft
        count++;
        for(int i=0;i<V;i++)
        {
            if(index!=i && graph[index][i] && !visited[i] && graph[index][i]<values[i])
            {
                values[i]=graph[index][i];
               // sum+=graph[index][i];
               
            }
        }
       
       // sum+=values[index];
    }
     for(int i=0;i<V;i++)
        sum+=values[i];
    return sum;
}
```
>Approach 2:
* Algo
> For krushkal you can use disjoint ds. First sort the edges and then check if any edge forms cycle or not in a loop of  v-1. If it forms a cycle ignore else include.
* Implementation
```
```
2. 
[Link](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/)
* Krushkal can be implemented using union-find



### Tarjan's Algorithm


Used to find Connected components and variation of Kosarajus algo.
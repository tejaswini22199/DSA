>https://practice.geeksforgeeks.org/problems/number-of-provinces/1/?company[]=Amazon&company[]=Amazon&difficulty[]=2&page=1&category[]=Graph&category[]=Graph%20colouring&query=company[]Amazondifficulty[]2page1company[]Amazoncategory[]Graphcategory[]Graph%20colouring#
```
class Solution {
  public:
    void dfs(vector<vector<int>> adj,vector<bool> & visited,int source,int V)
    {
        // if(visited[source])
        // return;
        visited[source]=true;
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && adj[source][i]==1)
            {
                dfs(adj,visited,i,V);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V,false);
       
        int count=0;
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(visited[i]==false && adj[i][j]==1)
                {
                    
                    dfs(adj,visited,i,V);
                    count++;
                }
            }
        }
        return count;
    }
};

```
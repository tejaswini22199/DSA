* Bipartite is a graph where 
```
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    queue<pair<int,int>> q;
	  
	    vector<pair<int,int>> visited(V,{0,-1});
	    for(int i=0;i<V;i++){
	        if(visited[i].first==0)
	        {
	            visited[i].first=1;
	            visited[i].second=0;
	              q.push({i,0});
	    while(!q.empty())
	    {
	        pair<int,int> source=q.front();
	        q.pop();
	        for(int i=0;i<adj[source.first].size();i++)
	        {
	            if(visited[adj[source.first][i]].first==0){
	                q.push({adj[source.first][i],1-source.second});
	                visited[adj[source.first][i]].first=1;
	                visited[adj[source.first][i]].second=1-source.second;
	            }
	           else if(visited[adj[source.first][i]].second==source.second)
	            {
	                return false;
	            }
	        }
	    }
	        }}
	    return true;
	}

};
```
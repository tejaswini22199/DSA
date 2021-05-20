>https://leetcode.com/contest/weekly-contest-240/problems/largest-color-value-in-a-directed-graph/

```
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adjacency_list;
        int n=colors.length();
        vector<int> indegree(n,0);
        queue<int> q;
        vector<vector<int>> max_Count(n,vector<int>(26,0));
        for(int i=0;i<edges.size();i++)
        {
            adjacency_list[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        for(int i=0;i<colors.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
            max_Count[i][colors[i]-'a']=1;
        }
        int count=0;
        int ans=INT_MIN;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            ans=max(ans,max_Count[u][colors[u]-'a']);
            count++;
            for(auto it:adjacency_list[u])
            {
                indegree[it]--;
                for(int i=0;i<26;i++)
                {
                     max_Count[it][i]=max(max_Count[it][i],max_Count[u][i]+(i==(colors[it]-'a')));
                }
                if(indegree[it]==0)
                    q.push(it);
               
            }
        }
        return count<colors.size()?-1:ans;
    }
};
```
class Solution {
public:
    int dfs(int node, int parent, vector<vector<vector<int>>>&adj){
        int ans=0;
        for(auto t:adj[node]){
            int child=t[0];
            int edgewt=t[1];
            if(child==parent)
                continue;
            ans+=edgewt+dfs(child,node,adj);
        }
        return ans;
    }
    vector<int>ans;
    void dfs2(int node,int parent,int val, vector<vector<vector<int>>>&adj){
        ans[node]=val;
        
        for(auto t: adj[node]){
            int child=t[0];
            int edgewt=t[1];
            if(child==parent)
                continue;
            if(edgewt==0){
                dfs2(child,node,val+1,adj);
            }
            else{
                dfs2(child,node,val-1,adj);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>>adj(n);
        ans=vector<int>(n,0);
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        int root=dfs(0,-1,adj);
        dfs2(0,-1,root,adj);
        return ans;
    }
};
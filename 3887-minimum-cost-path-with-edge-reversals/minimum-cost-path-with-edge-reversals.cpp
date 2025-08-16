class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>>adj(n);
        vector<vector<vector<int>>>radj(n);
        for(int i=0; i<edges.size(); i++){
            // cout
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            radj[v].push_back({u,2*w});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int>dist(n,1e9);
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto l=pq.top();
            pq.pop();
            int d=l[0];
            int node=l[1];
            if(d>dist[node])
                continue;
            for(auto j: adj[node]){
                int child=j[0];
                int wt=j[1];
                if(d+wt<dist[child]){
                    dist[child]=d+wt;
                    pq.push({d+wt,child});
                }
            }
            for(auto j: radj[node]){
                int child=j[0];
                int wt=j[1];
                if(d+wt<dist[child]){
                    dist[child]=d+wt;
                    pq.push({d+wt,child});
                }
            }
        }
        if(dist[n-1]>=1e9)
                return -1;
        return dist[n-1];
    }
};
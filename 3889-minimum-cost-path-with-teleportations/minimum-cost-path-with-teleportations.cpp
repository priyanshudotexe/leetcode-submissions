class Solution {
public:
    const int INF = 1e9;

    void solve(vector<vector<int>>& curr, vector<vector<int>>& gd) {
        int n = gd.size(), m = gd[0].size();
        curr[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    curr[i][j] = min(curr[i][j], gd[i][j] + curr[i - 1][j]);
                }
                if (j > 0) {
                    curr[i][j] = min(curr[i][j], gd[i][j] + curr[i][j - 1]);
                }
            }
        }
    }

    int minCost(vector<vector<int>>& gd, int k) {
        int n = gd.size(), m = gd[0].size();
        int ans = 0;
        vector<vector<int>> prev(n, vector<int>(m, INF)),
            curr(n, vector<int>(m, INF));

        // normal DP solve , as if k=0
        // >>>>>>>>>>>>>>>>>>
        // Start //
        solve(prev, gd);
        ans = prev[n - 1][m - 1];
        // End //
        // >>>>>>>>>>>>>>>>>>

        // we will give index to each element of grid accordong to their
        // position in sorted array of all elements. will give compressed
        // indexes , meaning same index to same valued elements. and So , we can
        // use map for this for entirety of problem , this "indexing" will
        // decide whether "teleport" is possible or not.
        // >>>>>>>>>>>>>>>>>>
        // Start //
        vector<int> ts;             // temporary vector to indexing
        unordered_map<int, int> mp; // map to store index
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ts.push_back(gd[i][j]);
            }
        }
        sort(ts.begin(), ts.end());
        ts.erase(unique(ts.begin(), ts.end()), ts.end());
        for (int i = 0; i < ts.size(); i++) {
            mp[ts[i]] = i;
        }
        // End //
        // >>>>>>>>>>>>>>>>>>

        while (k--) {

            // ith value of this "best" array , for all ts[i] valued elements of
            // grid , will contain minimum cost to reach that ts[i] valued
            // elements of grid from (0,0) with considering 1 teleportaion
            // privilege
            vector<int> best(ts.size(), INF);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    best[mp[gd[i][j]]] = min(best[mp[gd[i][j]]], prev[i][j]);
                }
            }
            // uptil here we have only considered teleportation among equal
            // valued elements.
            for (int i = ts.size() - 2; i >= 0; i--) {
                best[i] = min(best[i], best[i + 1]);
            }
            // now we have also considered possibility to be teleported here at
            // ts[i] valued elements from higher valued elements. now we have
            // found minimum cost of raching all ts[i] valued elements with
            // considering 1 more teleportation now just store this in curr
            // matrix for better representation and to use dp again
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    curr[i][j] = best[mp[gd[i][j]]];
                }
            }
            // now since the costs have changed we will need to run normal dp
            // again
            solve(curr, gd);

            ans = curr[n - 1][m - 1];

            // now swap the prev and curr for next iteration
            swap(prev, curr);
        }

        return ans;
    }
};
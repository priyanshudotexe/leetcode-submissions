class Solution {
public:
    vector<vector<int>> grid;
    int m, n;
    int fullmask;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    inline int f(int i, int j){
        return n * i + j;
    }
    int dfs(int x, int y, int mask) {
        if (grid[x][y] == 2) {
            if (mask == fullmask)
                return 1;
        }
        int ans=0;
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=m || ny>=n)
                continue;
            if(mask>>f(nx,ny)&1) continue;
            int newmask=mask|1<<f(nx,ny);
            ans+=dfs(nx,ny,newmask);
        }
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        fullmask = (1 << (m * n))-1;
        int mask = 0;
        int sx = 0;
        int sy = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                    mask |= (1 << (f(i,j)));
                }
                if(grid[i][j]==-1){
                    mask |= (1 << (f(i,j)));
                }
            }
        }
        return dfs(sx,sy,mask);
    }
};
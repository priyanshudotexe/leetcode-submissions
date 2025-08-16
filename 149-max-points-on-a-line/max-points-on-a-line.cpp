class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi = 1;
        int n=points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1, x2, y1, y2;
                x1 = points[i][0];
                y1 = points[i][1];
                x2 = points[j][0];
                y2 = points[j][1];
                int count=0;
                for (auto& p : points) {
                    int x = p[0];
                    int y = p[1];
                    if((x2-x1)*(y-y2)==(y2-y1)*(x-x2)){
                        count++;
                    }
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};
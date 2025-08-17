class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1000000007;
        for(auto &q: queries){
            int l=q[0];
            int r=q[1];
            int k=q[2];
            int v=q[3];
            for(int idx=l; idx<=r; idx+=k){
                nums[idx]=(nums[idx]*1LL*v)%mod;
            }
        }
        int ans=0;
        for(auto x: nums){
            ans^=x;
        }
        return ans;
    }
};
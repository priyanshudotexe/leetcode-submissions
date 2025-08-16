class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftmax(n,0);
        vector<int>rightmax(n,0);
        for(int i=1; i<n; i++){
            leftmax[i]=max(nums[i-1], leftmax[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            rightmax[i]=max(nums[i+1],rightmax[i+1]);
        }
        int ans=0;
        for(int i=1; i<n-1; i++){
            int mini=min(leftmax[i],rightmax[i]);
            ans+=max(mini-nums[i],0);
        }
        return ans;
    }
};
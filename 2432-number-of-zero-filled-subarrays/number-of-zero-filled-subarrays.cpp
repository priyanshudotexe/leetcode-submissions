class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        int cur=0;
        long long ans=0;
        for(int i=0; i<n; i++){
            if(nums[i]){
                ans+=(cur*1LL*cur+cur)/2;
                cur=0;
            }
            else{
                cur++;
            }
        }
        ans+=(cur*1LL*cur+cur)/2;
        return ans;
    }
};
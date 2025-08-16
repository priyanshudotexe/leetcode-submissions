class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int inf=n+1;
        for(int i=0; i<n; i++){
            if(nums[i]<1 || nums[i]>n)
                nums[i]=inf;
        }
        for(int i=0; i<n; i++){
            int t=abs(nums[i]);
            if(t<1 ||t>n)
                continue;
            t--;
            if(nums[t]>0){
                nums[t]*=-1;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]>0)
                return i+1;
        }
        return inf;
    }
};
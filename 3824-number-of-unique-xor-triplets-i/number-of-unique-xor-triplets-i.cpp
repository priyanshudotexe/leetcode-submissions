class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(__builtin_popcount(n)==1){
            return 2*n;
        }
        else{
            int i=1; 
            while(i<=n){
                i<<=1;
            }
            return i;
        }
    }
};
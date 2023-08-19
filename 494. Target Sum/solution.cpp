class Solution {
public:
    int solve(vector<int>&nums,int t,int index){
        //base condition
         if(index==-1 && t==0) return 1;
        if(index==-1) return 0;
       

        //choices
            int sub = solve(nums,t-nums[index],index-1);
            int add = solve(nums,t+nums[index],index-1);
            return add+sub;

    }
    int findTargetSumWays(vector<int>& nums, int t) {
        int n=nums.size();
        return solve(nums,t,n-1);
    }
};

class Solution {

    bool solve( vector<int>& nums,int i,vector<int>&dp){
        if(i==nums.size()-1){
            return true;
        }
        if(dp[i]!=-1) return dp[i];
        if(i>nums.size()-1){
            return false;
        }
        for(int k=1;k<=nums[i];k++){

            if(solve(nums,i+k,dp)) 

            {   dp[i]=1;
                return true;
            }
        }
        dp[i]=0;
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};
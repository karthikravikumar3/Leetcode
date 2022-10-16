class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp,0,sizeof(dp));
        dp[0]=nums[0];
        int sum=0;
        if(nums.size()==1){
            return nums[0];
        }
        dp[1]=max(nums[1],dp[0]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        /*for(auto x:dp){
            cout<<x<<"|";
        }*/
        return dp[nums.size()-1];
    }
};
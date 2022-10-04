class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size()+1;i++){
            count^=i;
        }
        for(int i=0;i<nums.size();i++){
            count^=nums[i];
        }
        return count;
    }
};
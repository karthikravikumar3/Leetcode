class Solution {
public:
    void rotate1(vector<int>& nums){
        int temp=nums[nums.size()-1];
        for(int i=nums.size()-1;i>0;i--){
            nums[i]=nums[i-1];
            //
        }
        nums[0]=temp;
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
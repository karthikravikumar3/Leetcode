class Solution {
public:
    bool check(vector<int>& nums) {
     int count=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                nums.insert(nums.end(),nums.begin(),nums.begin()+i+1);
                for(auto x:nums){
                    //cout<<x<<"|";
                }
                //cout<<endl;
                count=i;
                //cout<<count<<endl;
                break;
                
            }
        }
        for(int i=count+1;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }
};
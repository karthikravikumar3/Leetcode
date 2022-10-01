class Solution {
public:
    int findfirst(vector<int>& nums, int target){
        cout<<target<<endl;
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
   
    vector<int> searchRange(vector<int>& nums, int target) {
        int x1 = findfirst(nums,target);
        int x2=findfirst(nums,target+1)-1;
    if(x1<nums.size() && nums[x1]==target){
        return {x1,x2};
    }else{
        return {-1,-1};
    }
    }       
};
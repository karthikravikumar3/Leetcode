class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0]){
            return 0;
        }
        if(target>nums[nums.size()-1]){
            return nums.size();
        }
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high+1)/2;
            cout<<low<<"-"<<mid<<"-"<<high<<endl;
            if(nums[mid]==target){
                //cout<<"y1"<<endl;
                return mid;
            }else if(nums[mid]<target && nums[mid+1]>target){
                //cout<<"y2"<<endl;
                return mid+1;
            }else if(nums[mid]<target){
                //cout<<"y3"<<endl;
                low=mid+1;
                mid=low+high/2;
            }else{
                
                //cout<<"y4"<<endl;
                //cout<<nums[mid]<<"+++"<<target<<endl;
                high=mid-1;
                mid=low+high/2;
            }
        }
        return -989;
    }
};
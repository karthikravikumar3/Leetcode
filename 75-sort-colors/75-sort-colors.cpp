class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1,k=j;
        while(i<=j){
            cout<<nums[j]<<"-"<<endl;
            if(nums[j]==2){
                //cout<<"k"<<endl;
                swap(nums[k],nums[j]);
                j--;
                k--;
            }else if(nums[j]==0){
                swap(nums[j],nums[i]);
                i++;
                //j--;
            }else{
                j--;
            }
        }
    }
};
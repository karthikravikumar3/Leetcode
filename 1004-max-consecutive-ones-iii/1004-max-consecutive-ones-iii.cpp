class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int mx=0;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0){
                count++;
            }
            
                while(count>k){
                    cout<<"l"<<endl;
                    if(nums[i]==0){
                        count--;
                        
                    }
                    i++;
                
                    
                }
            
            j++;
            mx=max(j-i,mx);
        }
        return mx;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int arr[nums.size()];
        //memset(arr,0,sizeof(arr));
       
        //mp[0]++;
        arr[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            arr[i]=nums[i]+arr[i-1];
        }
        int count=0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(arr[i]==k){
                count++;
            }
            if(mp.find(arr[i]-k)!=mp.end()){
                //cout<<"i="<<i<<endl;
                //cout<<"k-"<<k<<" arr[i]="<<arr[i]<<" k-arr[i]="<<arr[i]-k<<endl;
                //auto itr = mp.find(arr[i]-k);
                //cout<<"itr->sec="<<itr->second<<endl;
                count+=mp[arr[i]-k];
                
                //mp.erase(itr);
            }
            mp[arr[i]]++;
        }
        
        
        return count;
    }
};

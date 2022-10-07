class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count=0;
        int i=0,j=k-1;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        if(sum/k>=threshold){
            count++;
        }
        while(j<arr.size()-1){
            j++;
            sum+=arr[j];
            sum-=arr[i];
            i++;
            
            if(sum/k>=threshold){
                count++;
            }
        }
        return count;
        
    }
};
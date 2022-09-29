class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[100]={0};
        int i=0,j=0;
        int count=0;
        while(j<s.size()){
            if(arr[s[j]-' ']==0){
                //cout<<"+-"<<s[j]<<endl;
                arr[s[j]-' ']++;
                j++;
            }else{
                while(arr[s[j]-' ']!=0){
                    //cout<<"--"<<s[i]<<endl;
                    arr[s[i]-' ']--;
                    i++;
                    
                }
            }
        count=max(count,j-i);
               
        }
        return count;
        
    }
};
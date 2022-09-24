class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        int arr[26]={0};
       // map<char,int> mp;
        for(char c:s1){
            arr[c-'a']++;
        }
        int i=0,j=0;
        for(i=0;i<s1.size();i++){
            arr[s2[i]-'a']--;
        }
    bool match=true;
        for(auto x:arr){
            if(x!=0){
                    match=false;
                    break;
                }
        }
        if(match==true)return true;
        
        cout<<"yo"<<endl;
        while(i<s2.size()){
            match=true;
            arr[s2[i]-'a']--;
            arr[s2[j]-'a']++;
            cout<<s2[j]<<"-"<<s2[i]<<endl;
            i++;
            j++;
            for(auto x:arr){
                if(x!=0){
                    match=false;
                    break;
                }
            }
            if(match==true)return true;
            
            
        }
        return false;
    }
};
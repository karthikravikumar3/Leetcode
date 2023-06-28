class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1){
            return 1;
        }
        set<char> st;
        int j=0;
        int mx=0;
        for(int i=0;i<s.size();i++){
            //cout<<"i-"<<i<<endl;
            mx=max(mx,i-j);
            if(st.count(s[i])){
                while(st.count(s[i])){
                    st.erase(s[j]);
                    j++;
                }
            }
            st.insert(s[i]);
        }
        int q=s.size();
        mx=max(mx,q-j);
        
        return mx;
    }
};
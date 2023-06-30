class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        vector<vector<int>> sol;
        sort(intervals.begin(),intervals.end());
        while(i<intervals.size()){
            if(i+1<intervals.size() && intervals[i][1]<intervals[i+1][0]){
                //cout<<"int-"<<intervals[i][0]<<endl;
                sol.push_back(intervals[i]);
                i++;    
            }else{
                
                int mn=intervals[i][0];
                int mx = intervals[i][1];
                //cout<<"mn-"<<mn<<" mx-"<<mx<<endl;
                while(i+1<intervals.size() && mx>=intervals[i+1][0]){
                    mx = max(mx,intervals[i+1][1]);
                    mn = min(mn, intervals[i+1][0]);
                    i++;
                }
                
                sol.push_back({mn,mx});
                i++;
            }
        }
        return sol;
    }
};
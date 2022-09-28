class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //int a = intervals.size();
        sort(intervals.begin(),intervals.end());
        int arr[intervals.size()];
        memset(arr,0,sizeof(arr));
        vector<vector<int>> sol;
        for(int i=0;i<intervals.size();i++){
            if(arr[i]==0){
                //cout<<"i-"<<i<<" intervals[i][0]-"<<intervals[i][0]<<endl;
                arr[i]++;
                pair<int,int> vx;
                vx.second=intervals[i][1];
                vx.first=intervals[i][0];
                if(i!=intervals.size()-1){
                    for(int j=i+1;j<intervals.size();j++){

                        if(vx.second>=intervals[j][0]&&(vx.second<=intervals[j][1]) || ((vx.first<=intervals[j][0])&&vx.second>=intervals[j][1])&& arr[j]==0){
                            //cout<<intervals[i][1]<<"<="<<intervals[j][0]<<" && "<<arr[j]<<endl;
                            //cout<<"j-"<<j<<" intervals[j][0]-"<<intervals[j][0]<<endl;
                            arr[j]++;
                            vx.first=min(vx.first,intervals[j][0]);
                            vx.second=max(vx.second,intervals[j][1]);
                        }
                    }
                }
                //if(vx.second==-1)vx.second=intervals[i][1];
                sol.push_back({vx.first,vx.second});
            }
        }
        return sol;
    }
};
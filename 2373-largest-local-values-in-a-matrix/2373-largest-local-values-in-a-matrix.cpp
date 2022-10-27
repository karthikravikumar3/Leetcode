class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        //int mx1=0;
        vector<vector<int>> v;
        for(int i=0;i<grid.size()-2;i++){
            vector<int> v1;
            for(int j=0;j<grid[i].size()-2;j++){
                int mx1=0;
                
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(grid[k][l]>mx1){
                            mx1=grid[k][l];
                        }
                    }
                }
                v1.push_back(mx1);
            }
            v.push_back(v1);
        }
        return v;
    }
};
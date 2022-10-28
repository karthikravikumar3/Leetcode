class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        /*int sum1=0,sum2=0;
        for(int i=0;i<matrix.size();i++){
            sum1^=i+1;
        }
        for(int i=0;i<matrix[0].size();i++){
            sum2^=i+1;
        }*/
        set<int> s;
        for(int i=0;i<matrix.size();i++){
            int q=0;
            for(int j=0;j<matrix[i].size();j++){
                s.insert(matrix[i][j]);
                //cout<<"q-"<<q<<endl;
            }
            //cout<<"i-"<<i<<" q="<<q<<" sum1-"<<sum1<<endl;
            if(s.size()!=matrix.size()){
                //cout<<"i-"<<i<<" q="<<q<<" sum1-"<<sum1<<endl;
                //cout<<"here1";
                return false;
            }
            s.clear();
            //q=0;
        }
        for(int i=0;i<matrix[0].size();i++){
            //int q=0;
            for(int j=0;j<matrix.size();j++){
                s.insert(matrix[j][i]);
            }
            if(s.size()!=matrix[0].size()){
                //cout<<"i-"<<i<<" q="<<q<<" sum2-"<<sum2<<endl;
                //cout<<"here";
                return false;
            }
            //q=0;
            s.clear();
        }
        return true;
    }
};
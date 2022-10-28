class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        bool flag=false;
        if(moves.size()==9)flag=true;
        vector<vector<int>> c(3,vector<int>(3,-1));
        vector<vector<int>> v(3,vector<int>(3,-1));
        for(int i=0;i<moves.size();i++){
            if(i%2==0){
                v[moves[i][0]][moves[i][1]]=1;
                
            }else{
                v[moves[i][0]][moves[i][1]]=0;
                
            }
            
        }
      
       
        if(v[0][0]==v[1][1] && v[1][1]==v[2][2] &&v[1][1]!=-1)return v[1][1]==1?"A":"B";
        //cout<<"9";
        if(v[0][2]==v[1][1] && v[1][1]==v[2][0] &&v[1][1]!=-1)return v[1][1]==1?"A":"B";
        //cout<<"1";
        for(int i=0;i<3;i++){
            if(count(v[i].begin(),v[i].end(),1)==3)return "A";
            if(count(v[i].begin(),v[i].end(),0)==3)return  "B";
        }
        //cout<<"12";
        
        for(int i=0;i<3;i++){
            //cout<<"hi-"<<v[0][i]<<v[1][i]<<v[2][i];
            if(v[0][i]==v[1][i]&& v[1][i]==v[2][i] &&v[1][i]!=-1){
                 //cout<<"i-"<<i<<endl;
                return v[1][i]==1?"A":"B";}
        }
        //cout<<"3";
        if(flag==false){
            return "Pending";
        }else{
            return "Draw";
        }
        
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       vector<vector<int>> v(9);
        vector<multiset<int>> r(9);
        vector<multiset<int>> c(9);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    int x= i/3;
                    v[x*3+j/3].push_back(board[i][j]-'0');
                    r[i].insert(board[i][j]-'0');
                    c[j].insert(board[i][j]-'0');
                    //cout<<board[i][j];
                }
                
            }
        }
        
        /*for(auto x:v){
            for(auto y:x){
                cout<<y<<"|";
            }
            cout<<endl;
        }*/
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int x = i/3;
               if(count(v[x*3+j/3].begin(),v[x*3+j/3].end(),board[i][j]-'0')>1 || r[i].count(board[i][j]-'0')>1 || c[j].count(board[i][j]-'0')>1){
                   return false;
               }
            }
        }
        return true;
    }
};
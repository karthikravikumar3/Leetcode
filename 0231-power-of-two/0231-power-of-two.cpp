class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        if(n<0){
            return false;
        }
        while(n>0){
            if(n%2==1){
                count++;
            }
            n=n/2;
        }
        //cout<<count;
        if(count==1){
            return true;
        }else{
            return false;
        }
    }
};
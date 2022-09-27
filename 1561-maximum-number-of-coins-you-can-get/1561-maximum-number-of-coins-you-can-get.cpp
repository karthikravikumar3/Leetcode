class Solution {
public:
    int maxCoins(vector<int>& piles) {
        deque<int> dq(piles.begin(),piles.end());
        sort(dq.begin(),dq.end());
        int sum=0;
        while(dq.size()!=0){
            dq.pop_back();
            sum+=dq.back();
            dq.pop_back();
            dq.pop_front();
        }
        return sum;
        
    }
};
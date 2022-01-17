class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int max=prices[0];
        int maxP=0;
        for(auto p: prices){
            if(p<min){
                if(maxP<max-min){
                    maxP=max-min;                   
                }
                min=p;
                max=p;
            }else if(p>max){
                max=p;
            }
        }
        
        if(maxP<max-min){
            maxP=max-min;                   
        }
                
        return maxP;
        
    }
};
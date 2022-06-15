class Solution { // AC but need to be optimized
public:
    int maxProduct(vector<int>& nums) {
        int index=0;
        int maxP=INT_MIN;
        while(index<nums.size()){
            if(nums.size()!=index && nums[index]==0){
                maxP=max(maxP, 0);
                index++;
                continue;
            }
            vector<int> prefixProduct(1, 1);
            int start=index;
            
            while(nums.size()!= index && nums[index]!=0) index++;
            int end=index-1;
            
            if(start==end){
                maxP=max(maxP, nums[start]);
                continue;
            }
            
            for(int i=start;i<=end;i++){
                prefixProduct.push_back(prefixProduct[i-start]*nums[i]);
            }
       
               
            int posMax=INT_MIN;
            int negMin=0;
            
            int negMax=INT_MIN;
            for(int i=1;i<prefixProduct.size();i++){
                int e=prefixProduct[i];
                if(e>0){
                    posMax=max(posMax, e);
                }else{
                    negMin=min(negMin, e);
                    negMax=max(negMax, e);
                }
            }
            
            int negP=negMin/negMax;
            
            maxP=max(maxP, max(posMax, negP));
            
            
        }
        return maxP;
    }
};


class Solution { //TLE
public:
    int maxProduct(vector<int>& nums) {
        int index=0;
        int maxP=INT_MIN;
        while(index<nums.size()){
            vector<int> prefixProduct(1, 1);
            int start=index;
            
            while(nums.size()!= index && nums[index]!=0) index++;
            int end=index-1;
            
            for(int i=start;i<=end;i++){
                prefixProduct.push_back(prefixProduct[i-start]*nums[i]);
            }
            
            
            for(int i=0;i<prefixProduct.size();i++){
                for(int j=i+1;j<prefixProduct.size();j++){
                    maxP=max(maxP, prefixProduct[j]/prefixProduct[i]);
                }
            }
            
            if(nums.size()!=index && nums[index]==0){
                maxP=max(maxP, 0);
            }
            index++;
        }
        return maxP;
    }
};
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
      int result=0;
        for(int target: nums){
          double range=sqrt(target);
          int i=1;
          int cnt=0;
          int sum=0;
          while(cnt<5 && i<=range){
            if(target%i==0){
                sum+=i;
                cnt++;

                if(target/i!=i){
                    sum+=target/i;
                    cnt++;
                }
            }
            i++;
          }
          if(cnt==4){
             result+=sum; 
          }
        }
      return result;
    }
};
// map will be more faster

class Solution {
public:
    static int higher(int a, int b){
        return a>b;
    }
    
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), higher);
        int result=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]<=i) break;
            result++;
        }
        return result;
    }
    

};
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
        
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int result=0;
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        for(auto box: boxTypes){

            int idx=box[0];
            int units=box[1];
            int usedIdx=truckSize>=idx ? idx : truckSize ;
            truckSize-=idx;
            result+=usedIdx*units;
            if(truckSize<0) return result;
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
    
        for(int i=1;i<intervals.size();i++){
            int first=intervals[i][0];
            int second=intervals[i][1];
            if(end >= first){
               end=end > second? end: second;   
            }else{
                result.push_back({start, end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        result.push_back({start, end});
        return result;
        
    }
};
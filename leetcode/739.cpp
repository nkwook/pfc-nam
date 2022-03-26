class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> s;
        for(int i=0;i<temperatures.size();i++){
            int cnt=1;
            while(!s.empty() && s.top().first < temperatures[i]){
                result[s.top().second]=i-s.top().second;
                s.pop();
                cnt++;
            }   
            s.push({temperatures[i], i});
        }
        
        
        return result;
    }
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { // O(NlgN)
        vector<int> result(temperatures.size(), 0);
        
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > pq;
        for(int i=0;i<temperatures.size();i++){
            bool condition=true;
            while(!pq.empty() && pq.top().first < temperatures[i]){
                int pos=pq.top().second;
                result[pos]=i-pos;
                pq.pop();
                
            }   
            pq.push({temperatures[i], i});
   
        }
        
        
        return result;
    }
};
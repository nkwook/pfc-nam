class Solution { //time complexity: 2^(candidates.size()+target/min) 
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int targetTemp=target;
        vector<vector<int>> result;
        vector<int> store;
        rec(candidates, result, store, target, candidates.size()-1);
        return result;
    }
    
    void rec(vector<int>& candidates, vector<vector<int>> &result, vector<int> store, int target, int cur){
        if(target<=0){
            if(target==0){
                result.push_back(store);
            }
            return;
        }
        if(cur>0){
            rec(candidates, result, store, target, cur-1);    
        }
        store.push_back(candidates[cur]);    
        rec(candidates, result, store, target-candidates[cur], cur);
            
        return;
    }
};


class Solution { //tc: O(candidate.length() ^ target/min) , iteration is faster than recursion?
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int targetTemp=target;
        vector<vector<int>> result;
        vector<int> store;
        rec(candidates, result, store, target, 0);
        return result;
    }
    
    void rec(vector<int>& candidates, vector<vector<int>> &result, vector<int> store, int target, int cur){
        if(target<=0){
            if(target==0){
                result.push_back(store);
            }
            return;
        }
        for(int i=cur;i<candidates.size();i++){
            store.push_back(candidates[i]);    
            rec(candidates, result, store, target-candidates[i], i);    
            store.pop_back();            
        }
        return;
    }
};
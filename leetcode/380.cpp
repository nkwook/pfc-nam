class RandomizedSet {
public:
    unordered_map<int, int> present;
    vector<int> v;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(present.find(val)==present.end() ){
            present[val]=v.size();
            v.push_back(val);
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(present.find(val)==present.end()){
            return false;
        }else{
            int idx=present[val];
            present.erase(val);          
            // int temp=v[idx];
            if(idx< v.size()-1){
                int endNum=v[v.size()-1];
                v[idx]=endNum;
                present[endNum]=idx;        
            }
            v.pop_back();
            return true;
        }
        
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
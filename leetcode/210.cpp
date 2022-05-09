class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> preNum(numCourses, 0);
        for(auto p: prerequisites){
            adj[p[1]].push_back(p[0]);
            preNum[p[0]]++;
        }
        
        queue<int> Q;
        for(int i=0;i<numCourses;i++){
            if(preNum[i]==0){
                Q.push(i);
            }
        }
        
        
        while(!Q.empty()){
            int course=Q.front();
            result.push_back(course);
            Q.pop();
            
            for(auto i: adj[course]){
                preNum[i]--;
                if(preNum[i]==0){
                    Q.push(i);
                }
            }
        }
        
        if(result.size()!=numCourses) return {};
        
        return result;
        
    }
};
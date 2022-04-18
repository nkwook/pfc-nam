class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int cntCourses=0;
        vector<vector<int> > adj(numCourses, vector<int>());
        vector<int> topologyCnt(numCourses, 0);
        queue<int> Q;
        for(auto p: prerequisites){
            int a=p[0];
            int b=p[1];
            adj[b].push_back(a);
            topologyCnt[a]++;
        }
        
        for(int i=0;i<numCourses;i++){
            if(topologyCnt[i]!=0) continue;
            Q.push(i);
        }
        
        while(!Q.empty()){
            int x=Q.front();
            Q.pop();
            cntCourses++;
            for(int i: adj[x]){
                topologyCnt[i]--;
                if(topologyCnt[i]==0) Q.push(i);
            }
        }
        
        
        return cntCourses==numCourses;
        
    }
};
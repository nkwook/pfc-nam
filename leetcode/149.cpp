class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int max=0;
            
        for(int i=0;i<points.size();i++){
            int xi=points[i][0];
            int yi=points[i][1];
            unordered_map<double, int> m;
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int xj=points[j][0];
                int yj=points[j][1];
                
                double slope;
                if(xi==xj){
                    slope=20001;
                 }else{
                    slope=(double)(yj-yi)/(double)(xj-xi);
                } 
                m[slope]++;
                if(max<m[slope]){
                    max=m[slope];
                }
            }
            
        }
        return max+1;
        
    }
};
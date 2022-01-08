#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m=matrix.size();
        int n=matrix[0].size();
        bool vis[10][10]={};
        
        int dx[4]={0, 1, 0, -1};
        int dy[4]={1, 0, -1, 0};
        int mode=0;
        int x=0;
        int y=0;
        for(int i=0;i<m*n;i++){
            
            result.push_back(matrix[x][y]);
            vis[x][y]=true;
            for(int j=0;j<4;j++){
                int nx=x+dx[mode];
                int ny=y+dy[mode];
                if(nx<0 || nx>=m || ny<0 || ny>=n){
                    mode++;
                    mode%=4;
                    continue;
                } 
                if(vis[nx][ny]){
                    mode++;
                    mode%=4;
                    continue;
                } 
                x=nx;
                y=ny;
                break;
            }
        }
        return result;
    }
};

int main(){
    Solution s;

    vector<vector<int> > vv={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> v=s.spiralOrder(vv);
    for(auto i:v){
        cout << i << ' ';
    }
    // while(r!=nullptr){
    //     cout << r->val << ' ';
    //     r=r->next;
    // }
    // // cout << s.mergeTwoLists(l1, l2);


}
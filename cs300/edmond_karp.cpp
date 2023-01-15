using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100
#define INF 100000000
int n=6, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end){
    while(1){
        cout << "Started loop \n";
        fill(d, d+MAX, -1);
        queue<int> Q;
        Q.push(start);
        while(!Q.empty()){
            int x=Q.front();
            Q.pop();
            for(int i=0;i<a[x].size();i++){
                int y=a[x][i];
                // cout << x << ", "<< y << ": " << c[x][y] << "- " << f[x][y] << '=' << c[x][y]-f[x][y] << '\n';
                if(c[x][y]-f[x][y]>0 && d[y]==-1){
                    // cout << "pushed\n";
                    Q.push(y);
                    d[y]=x; // record parent
                    if (y==end) break;
                }
            }
        }
        // for(auto i:d){
        //     cout << i << ' ';
        // }
        if (d[end]==-1) break;
        int flow=INF;
        for(int i=end;i!=start;i=d[i]){
            cout << "capa: " << c[d[i]][i] << ", f: " << f[d[i]][i] << '\n';
            flow=min(flow, c[d[i]][i]-f[d[i]][i]);
        }
        for(int i=end;i!=start;i=d[i]){
            cout << i << ' ' ;
            f[d[i]][i]+=flow;
            f[i][d[i]]-=flow;
        }

        cout << "\nadded flow: " << flow << '\n';

        result+=flow;
    }
}

int main(){
    a[1].push_back(2);
    a[2].push_back(1);
    c[1][2]=12;
    // c[2][1]=-12;
    
    a[1].push_back(4);
    a[4].push_back(1);
    c[1][4]=11;
    // c[4][1]=-11;
    
    a[2].push_back(3);
    a[3].push_back(2);
    // c[3][2]=-6;
    
    c[2][3]=6;
    
    a[2].push_back(4);
    a[4].push_back(2);
    // c[4][2]=-3;
    
    c[2][4]=3;
    
    a[2].push_back(5);
    a[5].push_back(2);
    // c[5][2]=-5;
    c[2][5]=5;

    a[2].push_back(6);
    a[6].push_back(2);
    // c[6][2]=-9;
    c[2][6]=9;

    a[3].push_back(6);
    a[6].push_back(3);
    c[3][6]=8;
    // c[6][3]=-8;
    

    a[4].push_back(5);
    a[5].push_back(4);
    c[4][5]=9;
    // c[5][4]=-9;

    a[5].push_back(3);
    a[3].push_back(5);
    c[5][3]=3;
    // c[3][5]=-3;
    
    a[5].push_back(6);
    a[6].push_back(5);
    c[5][6]=4;
    // c[6][5]=-4;
    

    maxFlow(1, 6);
    cout << result;
    
    
    
    
    
    
    
}
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int t;
int n, k;
int x, y, w;
vector<int> graph[1001];
int indegree[1001]={};
int waitTime[1001];
int buildTime[1001];
queue<int> Q;
//many test cases. need to initialize those all boxes

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--){     
        cin >> n >> k;
        int bt;
        for(int i=1;i<=n;i++){
            cin >> bt;
            waitTime[i]=bt;
            buildTime[i]=bt;
            indegree[i]=0;
            graph[i].clear();
        }
        while(!Q.empty()){
            Q.pop();
        }

        while(k--){
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }
        cin >> w;

        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                Q.push(i);
            }
        }

        while(!Q.empty() && Q.front()!=w){

            int front=Q.front();
            Q.pop();
            for(int x: graph[front]){
                if(waitTime[x] < buildTime[x]+waitTime[front]){
                    waitTime[x]=buildTime[x]+waitTime[front];
                }
                indegree[x]--;
                if(indegree[x]==0){
                    Q.push(x);
                }
            }
        }
        cout << waitTime[w] <<'\n';
    }
    return 0;
}
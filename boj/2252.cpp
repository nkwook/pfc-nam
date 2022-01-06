#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int n, m;
int a, b;
vector<int> adj[32001];
int indegree[32001]={};
vector<int> result;
queue<int> Q;

int main(){
    cin >> n >> m;
    
    while(m--){
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++; 

    }

    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            Q.push(i);
        }
    }

    int front=0;
    while(!Q.empty()){
        front=Q.front();
        Q.pop();
        result.push_back(front);
        for(int x: adj[front]){
            indegree[x]--;
            if(indegree[x]==0){
                Q.push(x);
            }
        }
    }

    for(int x: result){
        cout << x << " ";
    }

    return 0;


}
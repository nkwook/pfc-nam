#include <iostream>
using namespace std;
#include <vector>
#include <queue>

queue<int> Q;
vector<int> adj[100001];
int p[100001]={};
int n, u, v;

int main(){
    cin >> n;
    for(int i=1;i<=n-1;i++){

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Q.push(1);

    while(!Q.empty()){
        int node=Q.front();
        Q.pop();
        for(int i:adj[node]){
            if(p[i]!=0) continue;
            p[i]=node;
            Q.push(i);
        }
    }

    for(int i=2;i<=n;i++){
        cout << p[i] <<'\n';

    }

    
}
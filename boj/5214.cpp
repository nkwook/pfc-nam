using namespace std;
#include <iostream>
#include <vector>
#include <queue>

// 어렵군... 담에 정복하기로

int n, m, k;
vector<int> adj[101003];
// vector<int> adjH[1001];
int s;
queue<int> Q;
int dist[101003]={};
            
int main(){
    cin >> n >> k >> m ;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=k;j++){
            cin >> s;
            adj[s].push_back(i+n);
            adj[n+i].push_back(s);
        }
    }    
    Q.push(1);
    dist[1]=1;
    int node;
    bool succeed=false;
    while(!Q.empty()){
        node=Q.front();
        Q.pop();
        
        if(node==n){
            succeed=true;
            break;
        }

        for(auto t: adj[node]){
            if(dist[t]>0) continue;
            dist[t]=dist[node]+1;
            Q.push(t);
        }

    }
    

    if(n==1) cout << 1;
    else if(!succeed) cout << -1;
    else cout << dist[node]/2+1;
    

    



}
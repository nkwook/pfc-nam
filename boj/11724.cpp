#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1001];
int u, v;
int vis[1001]={};

//try dfs

void dfs(int x){
    vis[x]=1;
    for(int i: adj[x]){
        if(vis[i]!=1){
            dfs(i);
        }
    }
    return;
}

int main(){
    cin >> n >> m;

    while(m--){
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int size=0;
    
    for(int i=1;i<=n;i++){
        if(vis[i]!=1){
            size++;
            dfs(i);
        }

    }


    cout << size;

}
#include <iostream>
using namespace std;
#include <vector>

int n, r, q;
int qn;
int u, v;
vector<int> adj[100001];
bool vis[100001]={};
int nodes[100001]={};

// contraints condition will be better to check vis.

int dfs(int x){
    nodes[x]+=1; //itself
    // if(x!=r && adj[x].size()==1){
    //     return 1;
    // }
    if(vis[x]){
        return nodes[x];
    }
    vis[x]=true;
    
    for(int i: adj[x]){
        if(vis[i]) continue;
        nodes[x]+=dfs(i);
    }
    return nodes[x];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n>> r >> q;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }   

    dfs(r);

    while(q--){
        cin >> qn;
        cout << nodes[qn] <<'\n';
    }


}
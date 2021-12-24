#include <iostream>
using namespace std;

#include <vector>

vector<int > adj[1000001];
int enumber[1000001]={};
int isE[1000001]={};
bool vis[1000001]={};
int n, u, v;


int dfs(int x){
    if(adj[x].size()==1 && x!=1) return 1;

    vis[x]=true;
    int cnt=0;
    for(int i:adj[x]){
        if(vis[i]) continue;
        isE[x]+=dfs(i) ? 1 : !isE[i];
        cnt+=enumber[i];
    }
    enumber[x]=cnt+!!isE[x];
    return 0;
}

int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[1]=true;
    dfs(1);

    cout << enumber[1];

    
}
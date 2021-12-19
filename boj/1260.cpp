#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

// meaning of n--.....

vector<int> adj[1001];
int n, m, v;
int a, b;
int visB[1001]={};
int visD[1001]={};
queue<int> Q;

void dfs(int x){
    cout << x <<" ";
    visD[x]=1;
    for(int x: adj[x]){
        if(visD[x]==1 ) continue;
        dfs(x);
    }
    return;
}

void bfs(int v){
    cout << v << " ";
    visB[v]=1;
    Q.push(v);

    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for( int x: adj[x]){
            if(visB[x]==1) continue;

            visB[x]=1;
            cout << x << " ";
            Q.push(x);

        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> v;
    while(m--){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(n--){
        sort(adj[n+1].begin(), adj[n+1].end() );
    }

    dfs(v);

    cout << '\n';
    bfs(v);

    return 0;
}
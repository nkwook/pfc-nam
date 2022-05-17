#include<iostream>
using namespace std;
#include <vector>

int n;
int people[10001];
vector<int> adj[10001];
bool vis[10001];
int total[10001][2];

void check(int num){
    vis[num]=true;
    for(int i: adj[num]){
        if(vis[i]) continue;
        check(i);
        
        total[num][0]+= max(total[i][0],total[i][1]);
        total[num][1]+=total[i][0]; 
    }
    total[num][1]+=people[num];
    return;
}
int main(){
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> people[i];
        vis[i]=false;
        total[i][0]=0;
        total[i][1]=0;
    }

    int u, v;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    check(1);

    cout << max(total[1][0], total[1][1]);
}




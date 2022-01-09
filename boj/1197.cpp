#include <iostream>
using namespace std;
#include <queue>
#include <utility>
#include <tuple>

int v, e;
priority_queue< tuple<int, int, int> , 
    vector< tuple<int, int, int> > , 
    greater< tuple<int, int, int> > > pq;

vector< pair<int, int> > adj[10001];
bool chk[10001]={};


int main(){
    cin >> v >> e;
    int a, b, c;

    while(e--){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    chk[1]=true;
    for(auto i: adj[1]){
        int p=i.first;
        int w=i.second;
        pq.push(make_tuple(w, 1, p));
    }
    int weight=0;
    int cnt=1;
    while(cnt<v){
        tie(c, a, b)=pq.top();
        pq.pop();
        
        if(chk[b]) continue;
        weight+=c;
        cnt++;
        chk[b]=true;
        for(auto i:adj[b]){
            if(chk[i.first]) continue;
            pq.push(make_tuple(i.second, b, i.first));
        }
    }

    cout << weight;
    return 0;


}
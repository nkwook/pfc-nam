#include <iostream>
using namespace std;
#include <queue>
#include <tuple>
#include <utility>

// can reduce time complexity via graph remodeling.

int n;
priority_queue < tuple< int, int, int > ,
    vector<tuple<int, int, int > >,
    greater<tuple<int, int, int > > > pq;
bool chk[301]={};
int adj[301][301]={};

int main(){
    cin >> n;
    int w, p;
    int min=0;
    int minCost=100000;
    int minCostNum;
    for(int i=0;i<n;i++){
        cin >> w;
        min+=w;
        adj[i][i]=w;
        if(minCost>w){
            minCost=w;
            minCostNum=i;
        }
    }   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> p;
            if(i==j) continue;
            adj[i][j]=p;
        }
    }
    

    // for(int startingPoint=0;startingPoint<n;startingPoint++){

        for(int i=0;i<n;i++){
            chk[i]=false;
        }
        while(!pq.empty()){
            pq.pop();
        }

        for(int i=0;i<n;i++){
            pq.push(make_tuple(adj[minCostNum][i], minCostNum, i ));
            pq.push(make_tuple( adj[i][i], i, i));
        }

        int cnt=0;
        int cost=adj[minCostNum][minCostNum];
        chk[minCostNum]=true;

        int a, b, c;
        while(cnt<n-1){
            tie(c, a, b)=pq.top();
            pq.pop();
            if(chk[b]) continue;
            // cout << a << ' '<< b << ' ' << c << '\n';
            
            cost+=c;
            cnt++;
            chk[b]=true;
            for(int i=0;i<n;i++){
                if(chk[i]) continue;
                pq.push(make_tuple( adj[b][i], b, i));
            }
        }
        // cout << "cost: " << cost <<'\n';
        if(cost<min){
            min=cost;
        }

    // }
    cout << min;
    return 0;


}
#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#include <tuple>
#include <queue>
#include <algorithm>

// problem that made me to know situation to use union find and kruskal
// prim is fine but it become harder once theres too many edges
// so i had to make it simple by only considering near planets
// from the sight of the planet

int n;
priority_queue< tuple <int, int, int>, 
            vector<tuple<int, int, int> >,
            greater<tuple<int, int, int> > > pq;
vector<tuple<int, int, int> > planet[100001];
vector<pair<int, int> > x, y, z;
bool vis[100001]={};

int abs(int x){
    if(x<0) return -x;
    return x;
}

int main(){
    cin >> n;
    int xin, yin, zin;
    for(int i=1;i<=n;i++){
        cin >> xin >> yin >> zin;
        x.push_back(make_pair(xin, i));
        y.push_back(make_pair(yin, i));
        z.push_back(make_pair(zin, i));
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    for(int i=0;i<n-1;i++){
        int xd=abs(x[i].first-x[i+1].first);
        int yd=abs(y[i].first-y[i+1].first);
        int zd=abs(z[i].first-z[i+1].first);
        
        planet[x[i].second].push_back(make_tuple(xd, x[i].second, x[i+1].second));
        planet[x[i+1].second].push_back(make_tuple(xd, x[i+1].second, x[i].second));
        planet[y[i].second].push_back(make_tuple(yd, y[i].second, y[i+1].second));
        planet[y[i+1].second].push_back(make_tuple(yd, y[i+1].second, y[i].second));
        planet[z[i].second].push_back(make_tuple(zd, z[i].second, z[i+1].second));
        planet[z[i+1].second].push_back(make_tuple(zd, z[i+1].second, z[i].second));
    }

    int result=0;
    int cnt=0;
    int cur=0;
    int d, a, b;
    for(auto p: planet[1]){
        pq.push(p);

    }
    vis[1]=true;

    while(cnt<n-1){
        
        tie(d, a, b)=pq.top();
        pq.pop();
        if(vis[b]) continue;
        result+=d;
        vis[b]=true;
        for(auto p: planet[b]){
            pq.push(p);
        }
        cnt++;
    }
    cout << result;

}
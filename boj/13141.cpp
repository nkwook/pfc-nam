#include <iostream>
using namespace std;
#include <vector>
#include <tuple>

int n, m;
int arr[201][201];
const int MAX=9999999;
vector< tuple<int, int, int> > edges;

int main(){

    cin >> n >> m;
    int s, e, l;

    for(int i=1;i<=n;i++){
        fill(arr[i], arr[i]+1+n, MAX);
    }
    for(int i=1;i<=n;i++){
        arr[i][i]=0;
    }

    for(int i=0;i<m;i++){
        cin >> s >> e >> l;
        if(arr[s][e]>l){
            arr[s][e]=l;
            arr[e][s]=l;
        }
        edges.push_back(make_tuple(s, e, l));
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j] > arr[i][k]+arr[k][j]){
                    arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }


    double minTime=MAX;
    double localMax;

    for(int i=1;i<=n;i++){
        localMax=0;
        vector< tuple<int, int, int> > v;
        for(auto t: edges){
            v.push_back(t);
        } 
    
        double vt;
        for(tuple<int, int, int> &tup: v){
            int v1=get<0>(tup);        
            int v2=get<1>(tup);        
            int l=get<2>(tup);        
            vt=(double) (arr[i][v1]+arr[i][v2]+l)/2;

            if(vt>localMax) localMax=vt;
        }
        if(minTime > localMax) minTime=localMax;
    }

    // cout << fixed;
    cout<< fixed;
    cout.precision(1);
    cout << minTime;

    


}
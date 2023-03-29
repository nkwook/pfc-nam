#include <iostream>
using namespace std;
#include <map>
#include <set>
#include<vector>
int n, w;
int posters[2001][4];

map<int, set<tuple<int, int, bool>>> posterMap;
multiset<pair<int, bool>> yCoordinates;

int main(){
    int x1, x2, y1, y2;
    cin >> n;
    for( int i=0;i<n;i++){
        cin >> x1 >> x2 >> y1 >> y2;
        posterMap[x1].insert({y1, y2, true});
        posterMap[x2].insert({y1, y2, false});
    }   

    for (auto poster: posterMap){
        int pos=poster.first;
        for(auto it: poster.second){
            y1=get<0>(it);
            y2=get<1>(it);
            bool start=get<2>(it);
            yCoordinates.insert({y1, true});
            yCoordinates.insert({y2, false});
        }
    }




    return 0;
}
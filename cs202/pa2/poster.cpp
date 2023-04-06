#include <iostream>
using namespace std;
#include <map>
#include <set>
#include<vector>
long long n, w;
map<int, vector<tuple<long long, long long, bool>>> xCoordinates;
multiset<pair<long long, bool>> yCoordinates;

int main(){
    long long x1, x2, y1, y2;
    cin >> n;
    for( long long i=0;i<n;i++){
        cin >> x1 >> x2 >> y1 >> y2;
        xCoordinates[x1].push_back({y1, y2, true});
        xCoordinates[x2].push_back({y1, y2, false});
    }   

    long long preX=xCoordinates.begin()->first;

    long long result=0;
    for (auto xInfo: xCoordinates){

        long long x=xInfo.first;
        long long l=x-preX;
        long long preY=yCoordinates.begin()->first;
        long long cnt=0;
        long long occupiedNumber=0;
        long long newOccupiedNumber=occupiedNumber;
        for (auto it: yCoordinates){
            long long y=it.first;
            bool isStartY= it.second;

            if(isStartY){
                newOccupiedNumber++;
            }else{
                newOccupiedNumber--;
            }

            if(occupiedNumber>0 && newOccupiedNumber==0){
                cnt+= y-preY;
            }else if(occupiedNumber==0 && newOccupiedNumber>0){
                preY=y;

            }
            occupiedNumber=newOccupiedNumber;
        }
        result+=l*cnt;
        preX=x;

        for (auto xTuple: xInfo.second){
            long long y1=get<0>(xTuple);
            long long y2=get<1>(xTuple);
            bool isStartX=get<2>(xTuple);
            if(isStartX){
                yCoordinates.insert({y1, true});
                yCoordinates.insert({y2, false});
            }
            else{
                auto it1=yCoordinates.find({y1, true});
                auto it2=yCoordinates.find({y2, false});
                yCoordinates.erase(it1);
                yCoordinates.erase(it2);
            }
        }
    }
    cout << result;

    return 0;
}
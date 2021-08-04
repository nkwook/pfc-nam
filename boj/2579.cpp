#include <iostream>
#include <vector>
#include <utility>
using namespace std;


vector< pair<int, int> > D;
// 0, 1 
// cannot be 2
// also we can use 2d array instead of pair 
// lecture) using 1d arr ==> amazing... by changing the scope 
// 
// 
int stair[300];

int maxScore(int i){
     if(D[i].first > D[i].second){
        return D[i].first;
    }else{
        return D[i].second;
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> stair[i];
    }

    D.push_back(make_pair(stair[0], stair[0]));
    if(n==1){
        cout << stair[0];
        return 0;
    }
    D.push_back(make_pair(stair[1], stair[0]+stair[1]));

    for(int i=2;i<n;i++){
        D.push_back(make_pair( maxScore(i-2) + stair[i], D[i-1].first + stair[i]));
        
    }

    cout << maxScore(n-1);


    return 0;

}
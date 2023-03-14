#include <iostream>
using namespace std;
#include<set>

int m, n;
int demand[250001];
int minDemand[250001];
multiset<int> S;

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> demand[i];
    }


    for(int i=0;i<m;i++){
        S.insert(demand[i]);
    }


    for(int i=0;i<n;i++){
        minDemand[i]=*S.begin();
        S.insert(demand[(i+m)%n]);
        auto it=S.find(demand[i]);
        S.erase(it);
    }

    for(int i=0;i<n;i++){
        cout << minDemand[i] << ' ';
    }
    
    return 0;
}
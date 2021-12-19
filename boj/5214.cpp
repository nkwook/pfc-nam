using namespace std;
#include <iostream>
#include <vector>

// 어렵군... 담에 정복하기로

int n, m, k;
vector<int> adjS[100001];
vector<int> adjH[1001];
int s;
            
int main(){
    cin >> n >> k >> m ;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=k;j++){
            cin >> s;
            adjS[s].push_back(i);


        }

    }    

}
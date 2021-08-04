#include <iostream>
using namespace std;

int partsum[100001];
int num[100001];
/*
  ios::sync_with_stdio(0);
    cin.tie(0);
    this affects executing time... 
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    partsum[0]=0;
    for(int i=1;i<=n;i++){
        cin >> num[i];
        partsum[i]=partsum[i-1]+num[i];
    }

    while(m--){
        int i, j;
        cin >> i >>j;
        cout << partsum[j]-partsum[i-1] << '\n';

    }
    return 0;
}
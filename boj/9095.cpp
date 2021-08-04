#include <iostream>
using namespace std;

int D[12];

int main(){
    int n;
    cin >> n;

    D[1]=1;
    D[2]=2;
    D[3]=4;

    while(n--){
        int k;
        cin >> k;
        if(k<4){
            cout << D[k] << '\n';
            continue;
        }

        for(int i=4;i<=k;i++){
            D[i]=D[i-1]+D[i-2]+D[i-3];
        }
        cout << D[k] << '\n';

    }

    return 0;

}
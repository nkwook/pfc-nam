#include <iostream>
using namespace std;

int t;
int fzero[41];
int fone[41];

int main(){
    fzero[0]=1;
    fzero[1]=0;
    fone[0]=0;
    fone[1]=1;

    for(int i=2;i<41;i++){
        fzero[i]=fzero[i-1]+fzero[i-2];
        fone[i]=fone[i-1]+fone[i-2];
    }
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        cout << fzero[x] << " " << fone[x] << '\n';

    }
    return 0;
}
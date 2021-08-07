#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt=0;
    for(int i=0;i<n;i++){
        int k;
        bool nd=true;
        cin >> k;

        for(int j=2;j*j<=k;j++){
            if(k%j==0){
                nd=false;
                break;
            }
        }
        if(nd && k!=1)
            cnt++;
    }

    cout << cnt;

}
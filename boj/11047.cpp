#include <iostream>
using namespace std;

int value[11];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> value[n-1-i];
    }

    int cnt=0;
    int cur=0;
    while(k>0){

        if(k>=value[cur]){
            k-=value[cur];
            cnt++;
        }else{
            cur++;
        }

    }
    cout << cnt;



}
#include <iostream>
using namespace std;

int arr[1001];

int main(){
    int n;
    cin >> n;

    arr[1]=1;
    arr[2]=2;

    if(n<3){
        cout << arr[n];
        return 0;
    }

    for(int i=3;i<=n;i++){
        arr[i]=(arr[i-1]+arr[i-2])%10007; //avoid int overflow
    }

    cout << arr[n] % 10007;



}
#include <iostream>
using namespace std;

int arr[1005][1005];

int main(){
    int n, k;
    cin >> n >> k;

    arr[1][0]=1;
    arr[1][1]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0) arr[i][0]=1;
            else if(j==1) arr[i][1]=i;
            else arr[i][j]=(arr[i-1][j-1]%10007+arr[i-1][j]%10007)%10007;
        }
    }
    cout << arr[n][k];


}
#include<iostream>
using namespace std;

int n, m;
int arr[101][101];

int main(){
    cin >> n >> m;
    int a, b, c;
    for(int i=1;i<=n;i++){
        fill(arr[i], arr[i]+n+1, 10000000);
    }

    for(int i=1;i<=n;i++){
        arr[i][i]=0;
    }

    while(m--){
        cin >> a >> b >> c ;
        if(arr[a][b]>c){
            arr[a][b]=c;
            
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                int temp=arr[j][i]+arr[i][k];
                if(arr[j][k]> temp){
                    arr[j][k]=temp;
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]==10000000){
                cout << 0 << ' ';
            }else{
                cout << arr[i][j] << ' ';
            }
        }
        cout << '\n';
    }



}
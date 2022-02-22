#include<iostream>
using namespace std;
#include <queue>

queue<int> Q;
int n, m;
int arr[101][101];
int nxt[101][101]={};
const int MAX=10000000;

int main(){
    cin >> n >> m;
    int a, b, c;

    for(int i=1;i<=n;i++){
        fill(arr[i], arr[i]+1+n, MAX);
    }
    for(int i=1;i<=n;i++){
        arr[i][i]=0;
    }
    while(m--){
        cin >> a >> b >> c;
        if(arr[a][b]> c){
            arr[a][b]=c;
            nxt[a][b]=b;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j] > arr[i][k]+arr[k][j]){
                    arr[i][j]=arr[i][k]+arr[k][j];
                    nxt[i][j]=nxt[i][k];
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]==MAX) cout << "0 ";
            else cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j || arr[i][j]==MAX){
                cout << "0\n";
                continue;
            }

            int a=i;
            int b=j;
            bool condition=true;
            while(condition){
                Q.push(a);
                a=nxt[a][b];
                // cout << a << ' ' << b << ' ' << nxt[a][b] << "ddd \n";
                condition=a!=b;      
            }
            Q.push(b);
            cout << Q.size() << ' ';
            while(!Q.empty()){
                cout << Q.front() << ' ';
                Q.pop();
            }
            cout << "\n";

        
        }
    }    

}
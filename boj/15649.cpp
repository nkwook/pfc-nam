#include <iostream>
using namespace std;

int n, m;
int arr[10];
int used[10];


void backtrack(int k){
    cout << k <<'\n';
    if(k==m){   
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=1;i<=n;i++){
        if(!used[i]){
            arr[k]=i;
            used[i]=1;
            backtrack(k+1);
            used[i]=0;
        }
    }
    return;
}

int main(){
    cin >> n >> m;

    backtrack(0);
}
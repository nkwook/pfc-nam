#include <iostream>
using namespace std;

int n, m;
int arr[9];
int used[9];

void backtrack( int k){
    if(k==m){
        for(int i=0;i<k;i++){
            cout << arr[i] <<' ';
        }
        cout << '\n';
        return;
    }
    int st=1;
    if(k>0){
        st=arr[k-1]+1;
    }
    for(int i=st;i<=n;i++){
        if(used[i]) continue;
        
        arr[k]=i;
        used[i]=1;
        backtrack(k+1);
        used[i]=0; // able to go 2~


        
    }    

}


int main(){
    cin >> n >> m;
    backtrack(0);
}
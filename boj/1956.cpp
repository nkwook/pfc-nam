#include<iostream>
using namespace std;

int v, e;
int a, b, c;
int arr[401][401];
const int MAX=5000000;

int main(){
    cin >> v >> e;
    for(int i=1;i<=v;i++){
        fill(arr[i], arr[i]+1+v, MAX);
    }
    for(int i=1;i>=v;i++) arr[i][i]=0;
    while(e--){
        cin >> a>> b>> c;
        arr[a][b]=c;
    }
    
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                if(arr[i][j]> arr[i][k]+arr[k][j]){
                    arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }

    int minLength=MAX;
    int l=0;
    for(int i=1;i<=v;i++){
        for(int j=i;j<=v;j++){
            if(i==j) continue;
            l=arr[i][j]+arr[j][i];
            if(minLength>l) minLength=l;
        }
    }
    if(minLength==MAX) cout <<-1;
    else    cout <<minLength;

}
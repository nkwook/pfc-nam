#include<iostream>
using namespace std;

int n;
int arr[2200][2200];
int num[3]={};

int test(int x, int y, int size){
    for(int i=x; i<x+size;i++){
        for(int j=y; j<y+size;j++){
            if(arr[i][j]!=arr[x][y]) return 0;
        }
    }
    return 1;
}

void recursion(int size, int x, int y){
    if(size==1 || test(x, y, size)){
        num[arr[x][y]+1]+=1;
        return;
    }

    size/=3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            recursion(size, x+i*size, y+j*size);
        }
    }
    return;
}


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    recursion(n, 0, 0);

    cout << num[0] << '\n' << num[1] << '\n' << num[2];

    return 0;

}
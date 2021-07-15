#include <iostream>
using namespace std;

void draw(int x, int y, int n, char** arr){

    if(n==3){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==1 && j==1) continue;
                arr[x+i][y+j]='*';
            }
        }
        return;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int nx=x+i*n/3;
            int ny=y+j*n/3;
            if(i==1 && j==1) continue;
            draw(nx, ny, n/3, arr);
        }
    }
    return;
}


int main(){
    int n;
    cin >> n;


    char** arr;
    arr=new char *[n];
    for(int i=0;i<n;i++){
        arr[i]=new char[n];
    }
    draw(0, 0, n , arr);


    // cout << arr[0][0];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!='*') cout << " ";
            else cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}
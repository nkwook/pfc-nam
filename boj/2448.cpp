#include <iostream>
using namespace std;

// way to pass 2d array in func

void draw(int x, int y, int n, char** arr){

    if(n==3){
        arr[x][y+2]='*';
        arr[x+1][y+1]='*';
        arr[x+1][y+3]='*';
        for(int i=0;i<5;i++){
            arr[x+2][y+i]='*';
        }
        return;
    }

    draw(x, y+n/2, n/2, arr);
    draw(x+n/2, y, n/2, arr);
    draw(x+n/2, y+n, n/2, arr);

}


int main(){
    int n;
    cin >> n;


    char** arr;
    arr=new char *[n];
    for(int i=0;i<n;i++){
        arr[i]=new char[2*n];
    }
    draw(0, 0, n , arr);

    for(int i=0;i<n;i++){
        for(int j=0;j<2*n;j++){
            if(arr[i][j]!='*') cout << " ";
            else cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}
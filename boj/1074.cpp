#include <iostream>
using namespace std;

int move(int r, int c, int n){
    if(n==1){
        return 2*r+c;
    }

    int mid=(1<<(n-1));
    int inc=0;
    if(r>=mid){
        r=r-mid;
        inc+=(1<<2*n-1);
    }
    if(c>=mid){
        c=c-mid;
        inc+=(1<<2*n-2);
    } 
    return inc+move(r, c, n-1);
}

int main(){
    int n, r, c;
    cin >> n >> r >> c;

    cout << move(r, c, n);
}
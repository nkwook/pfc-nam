#include <iostream>
using namespace std;

int move(int a, int b, int k){
    if(k==1){
        cout << a << " " << b <<'\n';
        return 0;
    }

    move(a, 6-a-b, k-1);
    cout << a << " " << b <<'\n';
    move(6-a-b, b, k-1);
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << (1<<n)-1 << "\n";
    move(1, 3, n);



}


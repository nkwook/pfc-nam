#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    int result[10]={};
    cin >> a >> b >> c;
    int multiple= a*b*c;

    while( multiple >0 ){
        // cout <<multiple;
        result[multiple%10]++;
        multiple/=10;

    }

    for(int i=0;i<10;i++){
        cout << result[i] << '\n';
    }
}
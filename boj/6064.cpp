#include <iostream>
using namespace std;

// Think about situation: x/y/z
// 중국인의나머지정리?

int gcd(int m, int n){
    if(n==0) return m;
    return gcd(n , m%n);
}


int lcm(int m, int n){
    return m/gcd(m, n) *n;
}

int main(){
    int k;
    cin >> k;

    while(k--){
        int m, n, x, y;
        int success=0;
        cin >> m >> n >> x >> y;

        for(int i=x;i<= lcm(m, n);i+=m){
            if(i%n==y%n){
                cout << i << '\n';
                success=1;
                break;
            } 
        }
        if(!success){
            cout << -1 << '\n';
        }


    }   

}
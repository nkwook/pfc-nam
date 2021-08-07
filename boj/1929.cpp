#include <iostream>
#include <vector>
using namespace std;


int main(){
    int m, n;
    cin >> m >> n;

    // vector<int> primes;
    vector<bool> isPrime(n+1, true);

    isPrime[1]=false;
    // for(int i=m;i<=n;i++){
        for(int j=2;j*j<=n;j++){
            int k=j*j;
            while(m>k){
                k+=j;
            }
            for(;k<=n;k+=j){
                isPrime[k]=false;
            }

        }

        // }

    for(int i=m;i<=n;i++){
        if(isPrime[i])
            cout << i << '\n';

    }

}
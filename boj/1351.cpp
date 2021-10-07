#include <iostream>
using namespace std;
#include <unordered_map>

long long n, p, q;
unordered_map<long long, long long> m;

long long seq(long long l){
    if(l==0) return 1;
    else if(m.find(l) != m.end()){
        return m[l];
    }
    long long result=seq(l/p)+seq(l/q);
    m[l]=result;
    return result;
}

int main(){
    cin >> n >> p >> q;
    cout << seq(n);


}
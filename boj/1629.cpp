#include <iostream>
using namespace std;
using ll= long long;

// corner case: 2147483647 2147483647 2147483644

ll divide(ll a, ll b, ll c){
    if(b==1){
        return a%c;
    }

    if(b%2==1){
        return (divide(a, b-1, c)%c*a)%c;
    }else{
        int val=divide(a, b/2, c);
        return (val%c*val%c)%c;
    }

}

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    cout << divide(a, b, c);
    return 0;
}



// ll divide(ll a, ll b, ll c){
//     if(b==1){
//         return a%c;
//     }

//     int val=divide(a, b/2, c);
//     val=val*val%c;
//     if(b%2==1){
//         return val*a%c;
//     }
//     return val;
    

// }




#include <iostream>
using namespace std;

int k, n;
int lan[10001];

// messed up... we can use st or end also
// +1 => preventing infinite loop

int cal(long long x){
    long long result=0;
    for(int i=0;i<k;i++){
        result+=lan[i]/x;
    }
    return result;
}

int main(){
    cin >> k >> n;
    for(int i=0;i<k;i++){
        cin >> lan[i];
    }
    
    long long st=0;
    long long en=(1<<31)-1;

    // cout << en << '\n';
    // int x=1;
    long long mid;
    while(st<en){
        mid=(st+en+1)/2;
        int num=cal(mid);

        // cout << st << " " << en << " " << mid << " " << num << '\n';

        if(num>=n){
            st=mid;
        }else{
            en=mid-1;
        }
    }
    cout << st;


}
#include <iostream>
using namespace std;

int arr[20];
int n, s;

int backtrack(int k, int psum){
    int result=0;
    
    int sum=psum+arr[k];
    // cout << sum  << ' ' << k << '\n';

    if(sum==s){
        result++;
    }
    if(k!=n-1){
        result+=backtrack(k+1, sum);
        result+=backtrack(k+1, psum);

    }

    return result;
}

int main(){

    cin >> n >> s;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];

    }

    cout << backtrack(0, 0);

}
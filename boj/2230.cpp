#include <iostream>
using namespace std;
#include <algorithm>

int A[100001];

// 아예 처음에 경계끝에 엄청 큰 수 넣는 테크닉도 있음. 

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    sort(A+1, A+n+1);
    // int p1=1;
    int p2=2;
    int min=0x7fffffff;

    for(int p1=1;p1<n;p1++){
        // int p2=p1+1;
        while(p2<=n && A[p1]+m > A[p2] ){
            p2++;
        }
        if(p2==n+1){
            break;
        }
        
        int sub=A[p2]-A[p1];
        // cout << p1 <<" "<< p2 << " "<< sub << '\n';
        if(sub<min){
            min=sub;
        }
    }

    cout << min;

}
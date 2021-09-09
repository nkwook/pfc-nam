#include <iostream>
using namespace std;
#include <algorithm>

int arr[100001];

int main(){
    int n, s;
    cin >> n >> s;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }    

    int result=1000000;
    int psum=0;
    int p2=-1;

    for(int p1=0;p1<n;p1++){
        if(p1>0){
            psum-=arr[p1-1];
        }
        
        while(p2<n && psum<s){
            p2++;
            psum+=arr[p2];
        }
        if(psum>=s){

            // cout << p1 << " " << p2 <<" "<< psum << '\n';
            int length=p2-p1+1;
            if(result > length){
                result=length;
            }
        }
    }

    if(result==1000000){
        result=0;
    }
    cout << result;


}
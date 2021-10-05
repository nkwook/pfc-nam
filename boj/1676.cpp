#include<iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    int num=0;
    for(int i=5;i<=n;i+=5){
        int t=i;
        while(t%5==0){
            num++;
            t/=5;
        }
    }
    cout << num;

}
#include <iostream>
#include <algorithm>
using namespace std;

int a[50], b[50];

bool cmp(int a, int b){
    return a>b;
}

int main(){
    int n;
    cin >> n;
         
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    sort(b, b+n);
    sort(a, a+n, cmp);


    int result=0;
    for(int i=0;i<n;i++){
        result+= a[i]*b[i];
    }

    cout << result;

}
#include <iostream>
using namespace std;
#include <algorithm>
int a[100001];
int b[100001];

int n, m;

int bs(int t, int st, int en){
    if(st > en || a[st] > t || a[en] < t){
        return 0;
    }
    int mid=(st+en)/2;

    if(a[mid]==t || a[st]==t || a[en]==t){
        return 1;
    }
    else if(a[mid]> t && a[st] < t){
        return bs(t, st, mid-1);
    }else{
        return bs(t, mid+1, en);
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cin >> m;
    for(int i=0;i<m;i++){
        cin >> b[i];
    }

    sort(a, a+n);
    
    for(int i=0;i<m;i++){
        cout << bs(b[i], 0, n-1) << '\n';
    }
}

#include <iostream>
using namespace std;
#include <algorithm>

int n;
int tarr[1000001];
int arr[1000001];
int narr[1000001];

/*
    tip: using lower bound function(when we use iterator, 
    we should subtract begin)
    
    tip: stl unique + erase on vector!!! wow wow wow
*/

int bsearch(int t, int size){
    int st=0;
    int en=size-1;

    // cout << size << '\n';
    int result=0;
    while(st<=en){
        int mid=(st+en)/2;
        // cout << "??";
        if(narr[mid]==t){
            result=mid;
            break;
        }else if(narr[mid]<t){
            st=mid+1;
        }else{
            en=mid-1;
        }
    }
    return result;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        tarr[i]=arr[i];
    }

    sort(arr, arr+n);

    int j=1;
    narr[0]=arr[0];
    for(int i=0;i<n-1;i++){
        
        if(arr[i]!=arr[i+1]){
            narr[j]=arr[i+1];
            j++;
        }
    }

    int size=j;

    for(int i=0;i<n;i++){
        cout << bsearch(tarr[i], size) << " ";
   
    }
    
}
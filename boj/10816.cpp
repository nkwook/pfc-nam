#include <iostream>
using namespace std;
#include <algorithm>

// finding numbers in arr!!!

// idea: inserting, comparing!
// be careful about exceptions... there gonna actually work?

// We can simplify this with combining <, =


int n, m;
int cards[500001];
int nums[500001];


int bsearch(int t){
    // cout << t << '\n';
    int st=0;
    int en=n;

    int front=-1; 
    int back=-1;
    int mid;
    while(st<en){
        mid=(st+en)/2;
        // cout << mid << "\n";

        if( cards[mid] >= t){
            en=mid;
        }
        else {
            st=mid+1;
        }
    }
    front=st;
    // cout << front << '\n';
    // if(front==-1){
    //     return 0;
    // }
    
    en=n;
    st=front;
    while(st< en){

        mid=(st+en)/2;
        // cout << mid << " ";

        if( cards[mid] <= t){
            st=mid+1;
        }
        else {
            en=mid;
        }    
    }
    back=st;

    // cout << back << " " << front << '\n';
    return back-front;
}


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> cards[i];
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> nums[i];
    }

    sort(cards, cards+n);

    for(int i=0;i<m;i++){
        // cout <<  nums[i]<< "\n";
        cout << bsearch(nums[i]) << ' ';
    }

    return 0;
}
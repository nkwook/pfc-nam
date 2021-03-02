#include <iostream>
using namespace std;

int main(){
    int length, n;
    cin >> length;
    cin >> n;

    int arr[length];
    for(int i=0;i<length;i++){
        cin >> arr[i];
    }

    for (int j=0;j<length;j++){
        if(arr[j]<n){
            cout << arr[j];
            cout << " ";
        }
    }

}
#include <iostream>
using namespace std;

int main(){
    int number, v;
    int result=0;
    cin >> number;

    int arr[number];

    for(int i=0;i<number;i++){
        cin >> arr[i];
    }
    cin >> v;

    for(int i=0;i<number;i++){
        if(v==arr[i]){
            result++;
        }
    }
    cout << result;


}
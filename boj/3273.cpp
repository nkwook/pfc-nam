#include <iostream>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    int inputArray[n];
    for(int i=0;i<n;i++){
        int input;
        cin >> input;
        inputArray[i]=input;
    }

    // be aware of out of bounds that are 
    // even not able to be contained in array to store
    // In that case, vectors or iterators could be considered.

    cin >> x;
    int resultArray[x];
    fill(resultArray, resultArray+sizeof(resultArray)/4, 0);
    int result=0;

    for(int j: inputArray){
        if(x-j-1>=0){
            if(resultArray[x-j-1]>0){ 
                result++;
            }
            resultArray[j-1]++;
            
        }
    }
    
    cout << result;

}
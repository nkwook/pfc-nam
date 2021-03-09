#include <iostream>
#include <stack>
using namespace std;

int main(){
    int number;
    cin >> number;
    stack<int> numStack;
    stack<int> hStack;
    int hArray[number];
    long result=0; // wow freaking data type..!! if N & result estimated as big, we can try it.

    for(int i=0;i<number;i++){
        cin >> hArray[i];
    }

    for(int i=number-1;i>=0;i--){
        while(!hStack.empty()){
            if(hStack.top() < hArray[i]){
                numStack.pop();
                hStack.pop();
            }else{
                result+= (numStack.top()-i-1);
                numStack.push(i);
                hStack.push(hArray[i]);
                break;
            }

        }

        if(hStack.empty()){
            numStack.push(i);
            hStack.push(hArray[i]);
            result+= (number-i-1);
        }
    }
    cout << result;

}
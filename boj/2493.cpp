#include <iostream>
using namespace std;
#include <stack>

int main(){
    int number;
    cin >> number;

    // time exceed... need to use stack
    // read solution about half... TT
    // If theres condition that relations by time are ignored, 
    // we can approach stack +  saving index also by using 2 stacks
    int heightArray[number];
    stack<int> numStack;
    stack<int> heightStack;
    for(int i=0;i<number;i++){
        cin >> heightArray[i];
    }

    for(int i=0;i<number;i++){
        while(!heightStack.empty()){
            if(heightStack.top() < heightArray[i]){
                heightStack.pop();
                numStack.pop();
            }else{
                cout << numStack.top() << ' ';
                heightStack.push(heightArray[i]);
                numStack.push(i+1);
                break;
            }
        }
        if(heightStack.empty()){
            heightStack.push(heightArray[i]);
            numStack.push(i+1);
            cout << 0 << ' ';
        }        

    
    }

}
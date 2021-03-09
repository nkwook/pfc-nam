#include <iostream>
#include <stack>
using namespace std;

int main(){
    int number;
    cin >> number;
    int seq[number];
    stack<int> storage;
    stack<int> s;

    for( int i=0;i<number;i++){
        cin >> seq[i];
        storage.push(number-i);
    }    
    // discriminate
    int max=seq[0];
    for(int i=0;i<number-1;i++){
        if(seq[i]<seq[i+1]){
            if(max > seq[i+1]){
                cout << "NO";
                return 0;
            }
        }
        if(seq[i]>max){
            max=seq[i];
        }
    }

    for(int i: seq){
        if(s.empty()){ //push something when empty
            s.push(storage.top());
            storage.pop();
            cout << "+\n";
        }
        //compare top of s, i
        while(s.top()<i){
            s.push(storage.top());
            storage.pop();
            cout << "+\n";
        }
        s.pop();
        cout << "-\n";
    }

}
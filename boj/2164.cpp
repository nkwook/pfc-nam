#include <iostream>
using namespace std;
#include <queue>

int main(){
    int number;
    cin >> number;

    queue<int> q;
    for(int i=1;i<=number;i++){
        q.push(i);
    }
    while(q.size()>1){
        q.pop();
        int top=q.front();
        q.pop();
        q.push(top);
    }

    cout << q.front();



}
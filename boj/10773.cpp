#include <iostream>
#include <stack>
using namespace std;

int main(){
    int k;
    int sum =0;
    cin >> k;
    stack<int> s;

    for(int i=0;i<k;i++){
        int x;
        cin >> x;

        if(x){
            s.push(x);
        }else{
            if(!s.empty()){
                s.pop();
            }
        }
    }

    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    cout << sum;

}
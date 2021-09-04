#include <iostream>
using namespace std;
#include <stack>
#include <queue>

stack<int> S;
queue<char> result;

int main(){
    int n;
    cin >> n;
    int seq[n];

    for(int i=0;i<n;i++){
        cin >> seq[i];
    }

    int t=1;
    for(int i:seq){
        while(true){
            // cout << i << '\n';
            if(S.empty()){
                S.push(t);
                result.push('+');
                t++;
            }else if(S.top()<i){
                S.push(t);
                result.push('+');
                t++;
            }else if(S.top()==i){
                result.push('-');
                S.pop();
                break;
            }else{
                cout << "NO";
                return 0;
            }
 
        }
    }

    while(!result.empty()){
        cout << result.front() << '\n';
        result.pop();
    }



}
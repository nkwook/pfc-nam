#include <iostream>
// #include <stack>
using namespace std;

int stack[10005];
int pos=0;

void push(int x){
    stack[pos++]=x;
}

void pop(){
    if(pos==0){
        cout << -1 << '\n';
    }else{
        pos--;
        cout << stack[pos] << '\n';
    }

}

void size(){
    cout << pos << '\n';
}

void empty(){
    if(pos==0){
        cout << 1 << '\n';
    }else{
        cout << 0 << '\n';
    }
}

void top(){
    if(pos==0){
        cout << -1 << '\n';
    }else{
        cout << stack[pos-1] << '\n';
    }
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int number;
    cin >> number;

    for(int i=0;i<number;i++){
        string command;
        cin >> command;

        if(command == "push"){
            int x;
            cin >> x;
            push(x);
        }else if( command == "pop"){
            pop();
        }else if( command =="size"){
            size();
        }else if(command=="empty"){
            empty();
        }else if(command=="top"){
            top();
        }else{
            cout << "error";
        }

    }
}

#include <iostream>
using namespace std;


int head=0;
int tail=0;
int queue[10005];

void push(int x){
    queue[tail++]=x;
}
void pop(){
    if(head==tail){
        cout << -1 << '\n';
    }else{
        cout << queue[head] << '\n';
        head++;
    }
}
void size(){
    cout << tail-head << '\n';
}
void empty(){
    if(head==tail) cout << 1 << '\n';
    else cout << 0 << '\n';
}
void front(){
    if(head==tail){
        cout  <<-1 << '\n';
    }else{
        cout << queue[head] << '\n';
    }
}
void back(){
    if(head==tail){
        cout  << -1 << '\n';
    }else{
        cout << queue[tail-1] << '\n';
    }
}
int main(){
    int number;
    cin >> number;
    while(number){
        string command;
        cin >> command;
        // cout << tail << ",";
        if(command=="push"){
            int x;
            cin >> x;
            push(x);
        }else if( command =="pop") pop();
        else if(command=="size") size();
        else if(command=="empty") empty();
        else if( command == "front") front();
        else if( command == "back") back();


        number--;
    }


}

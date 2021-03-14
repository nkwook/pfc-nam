#include <iostream>
using namespace std;
#include <list>

// list implementation

list<int> deque;


void push_front(int x){
    deque.push_front(x);
}
void push_back(int x){
    deque.push_back(x);
}
void pop_front(){
    if(deque.size()){
        cout << deque.front() << '\n';
        deque.pop_front();
    }else{
        cout << -1 << '\n';
    }
}
void pop_back(){
    if(deque.size()){
        cout << deque.back() << '\n';
        deque.pop_back();        
    }else{
        cout << -1 << '\n';
    }
}
void size(){
    cout << deque.size() << '\n';
}
void empty(){
    cout << deque.empty() << '\n';
}
void front(){
    if(deque.empty()){
        cout << -1 << '\n';
    }else{
        cout << deque.front() << '\n';
    }
}
void back(){
    if(deque.empty()){
        cout << -1 << '\n';
    }else{
        cout << deque.back() << '\n';
    }
}
int main(){
    int number;
    cin >> number;

    while(number){
        string c;
        cin >> c;
        if(c=="push_front"){
            int x;
            cin >> x;
            push_front(x);
        }else if(c=="push_back"){
            int x;
            cin >> x;
            push_back(x);
        }
        else if(c=="pop_front") pop_front();
        else if(c=="pop_back") pop_back();
        else if(c=="size") size();
        else if(c=="empty") empty();
        else if(c=="front") front();
        else if(c=="back") back();
        
        number--;
    }

}
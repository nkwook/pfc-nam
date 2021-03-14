#include <iostream>
using namespace std;
#include <list>

// circular queue? lets use list

int head=0;
int tail=0;
list<int> queue;
auto h=queue.begin();
auto t=queue.end();

void push(int x){
    queue.insert(t, x);
    // t++;
}
void pop(){
    if(!queue.size()){
        cout << -1 << '\n';
    }else{
        cout << queue.front() << '\n';
        // auto s=queue.begin();
        // s=queue.erase(s);
        queue.erase(queue.begin());
        /*
         mystery.....?
         when we try to erase specific location in list,
         define it..... hmmm  I think its not a good way
         ah fuck I got it 
         position ofiterator that defined first part of code
         has changed due to push operation.....
         Hooo....
        */
    }
}
void size(){
    cout << queue.size() << '\n';
}
void empty(){
    if(!queue.size()) cout << 1 << '\n';
    else cout << 0 << '\n';
}
void front(){
    if(!queue.size()){
        cout  <<-1 << '\n';
    }else{
        cout << queue.front() << '\n';
    }
}
void back(){
    if(!queue.size()){
        cout  << -1 << '\n';
    }else{
        cout << queue.back() << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
        }
        else if( command =="pop") pop();
        else if(command=="size") size();
        else if(command=="empty") empty();
        else if( command == "front") front();
        else if( command == "back") back();

        cout << *t << ",\n";

        // for(auto i: queue){
        //     cout << i << ",";
        // }
        // cout << '\n';
        number--;
    }


}

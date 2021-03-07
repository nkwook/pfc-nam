#include <iostream>
#include <list>
using namespace std;

int main(){
    list<char> L;
    L.push_back('a');
    L.push_back('b');
    L.push_back('c');
    auto t=L.begin();
    for(int i=0;i<20;i++){
        cout << *t << i;
        t=next(t);
  
        
        
    }
}
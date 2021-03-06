#include <iostream>
#include <list>
using namespace std;

int main(){
    list<char> L;
    L.push_back('b');
    L.push_back('c');

    auto t=L.end();
    cout << *t;
}
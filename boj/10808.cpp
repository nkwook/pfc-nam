#include <iostream>
using namespace std;

int main(){
    string s;

    cin >> s;
    int result[26]={};

    // lets try using ascii.

    for(char c: s) {  // iterating!
        // cout << c;
        result[(int)c-97]++;
    }

    for(int i=0;i<26;i++){
        cout << result[i] << ' ';
    }

}
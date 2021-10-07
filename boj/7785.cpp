#include <iostream>
using namespace std;
#include <vector>
#include<unordered_set>
#include <algorithm>

int n;
unordered_set<string> h;
vector<string> v;

bool reversed(string a, string b){
    if(a<b) return false;
    else return true;
}

int main(){
    cin >> n;
    while(n--){
        string a, b;
        cin >> a >> b;
        if(b=="enter"){
            h.insert(a);
        }else{
            h.erase(a);
        }
    }


    for(string s:h){
        v.push_back(s);
    }    
    sort(v.begin(), v.end(), reversed);
    // v.
    // sort(v.begin(), v.end());

    for(string s: v){
        cout << s << '\n';
    }
    return 0;
}
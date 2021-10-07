#include <iostream>
using namespace std;
#include <unordered_map>

int n, m;
unordered_map<string, int> pokemap;
string arr[100001];

// wat to check type, stoi function;

int main(){
    cin.tie(0);
    cin >> n >> m;
    string s;

    for(int i=1;i<=n;i++){
        cin >> s;
        arr[i]=s;
        pokemap[s]=i;
    }

    while(m--){
        // string s;
        cin >> s;
        if(isdigit(s[0])){
            cout << arr[stoi(s)] <<'\n';
        }else{
            cout << pokemap[s] << '\n';
        }
        // cout << '\n';
    }
    return 0;

}
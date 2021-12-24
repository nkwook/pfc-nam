#include <iostream>
using namespace std;

char r[27]={};
char l[27]={};
int n;
char node, ln, rn;


void preOrder(char c){
    cout << c;
    if(l[c-'A']!='a') preOrder(l[c-'A']);
    if(r[c-'A']!='a') preOrder(r[c-'A']);
    return;
}
void inOrder(char c){
    if(l[c-'A']!='a') inOrder(l[c-'A']);
    cout << c;
    if(r[c-'A']!='a') inOrder(r[c-'A']);
    return;
}
void postOrder(char c){

    if(l[c-'A']!='a') postOrder(l[c-'A']);
    if(r[c-'A']!='a') postOrder(r[c-'A']);
    cout << c;
    return;
}


int main(){
    cin >> n;

    for(int i=0;i<27;i++){
        l[i]='a';
        r[i]='a';
    }
    for(int i=1;i<=n;i++){
        cin >> node >> ln >> rn;
        if(ln!='.') l[node-'A']=ln;
        if(rn!='.') r[node-'A']=rn;
        // it'll be zero-indexed
    }
    preOrder('A');
    cout << '\n';
    inOrder('A');
    cout << '\n';
    postOrder('A');
    cout <<'\n';   
}
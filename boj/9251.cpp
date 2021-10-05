#include <iostream>
using namespace std;
#include <string>

string a, b;
int lcs[1001][1001];

int max(int x, int y){
    if(x>y) return x;
    else return y;
}

int main(){
    cin >> a >> b;

    int lA=a.length();
    int lB=b.length();
    // int max=0;
    // int store=0;

    for(int i=0;i<lA;i++){
        for(int j=0;j<lB;j++){
    
             
            if(a.at(i)==b.at(j)){
                if(i==0 || j==0) lcs[i][j]=1;
                else lcs[i][j]=lcs[i-1][j-1]+1;
            }else{
                if(i==0 && j==0) continue;
                else if(i==0) lcs[i][j]=lcs[i][j-1];
                else if(j==0) lcs[i][j]=lcs[i-1][j];
                else lcs[i][j]=max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
    }

    cout << lcs[lA-1][lB-1];
    return 0;
}
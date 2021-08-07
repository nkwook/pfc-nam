#include <iostream>
using namespace std;
#include <vector>

vector<int>  factor;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int i=2;
    while(n!=1){
        if(n%i==0){
            n/=i;
            factor.push_back(i);
        }else{
            i++;
        }

        if(n<i*i && n!=1){
            factor.push_back(n);
            break;
        } 
    }

    // sort(factor.)
    for(int i=0;i<factor.size();i++){
        cout << factor[i] << '\n';
    }



}
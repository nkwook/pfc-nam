#include <iostream>
using namespace std;

int coulmnUsed[15]={};
int diagUsed[30]={};
int diagUsed2[30]={};

int backtrack(int x, int n){
    int result=0;

    if(x==n){
        return 1;
    }

    for(int i=0; i<n;i++){
        // if(i==n-1) continue;
        if(coulmnUsed[i]==0 && diagUsed[i+x]==0 
        && diagUsed2[n-1+x-i] ==0){
            coulmnUsed[i]=1;
            diagUsed[i+x]=1;
            diagUsed2[n-1+x-i]=1;
        
            result+=backtrack(x+1, n);
            coulmnUsed[i]=0;
            diagUsed[i+x]=0;
            diagUsed2[n-1+x-i]=0;
        }
       

    }

    return result;
}


int main(){
    int n;
    cin >> n;
    
    cout << backtrack(0, n);


    return 0;
    
}
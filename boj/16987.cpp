#include <iostream>
using namespace std;
#include <vector>

int n;
int eggs[9];
int eggw[9];
int maxim=0;

// fucking easy but took long time sibal
/*
    undoing modifications after backtrack recur is important
    if confused, just print k and follow.
    also, consider exceptions such as continuing, 
    imagine what will happen when skipping cases

*/
 

void backtrack(int k){
    // cout << "k " << k << '\n';
    if(k==n){
        int result=0;
    
        for(int i=0;i<n;i++){
        //     cout << eggs[i] << " " ;
            if(eggs[i]<=0) result++;
        }
        // cout << '\n';
        if(result>maxim) maxim=result;
        return;
    }

    if(eggs[k]<=0){
        backtrack(k+1);
        return;   
    }

    for(int j=0;j<n;j++){
        if(eggs[j]<=0 || k==j) {
            continue;
        };
        eggs[j]-=eggw[k];
        eggs[k]-=eggw[j];

        backtrack(k+1);
        // cout << k << " ??";
        eggs[j]+=eggw[k];
        eggs[k]+=eggw[j];

    }
    // }
    backtrack(n); // 다 continue 되었을 때.
    //flag 넣어주는게 맞긴하지
    return ;
}


int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        int s, w;
        cin >> s >> w;
        eggs[i]=s;
        eggw[i]=w;
    }

    backtrack(0);

    cout << maxim;


}
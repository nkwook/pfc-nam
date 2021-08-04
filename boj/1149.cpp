#include <iostream>
using namespace std;

int cost[1005][3];
int info[1005][3];

// TIL: setting rules which one to put in cost arr is real important
// in this case: compared past data -> appropriate for dp
// min_element , min 

int min(int i, int a, int b){
    if(cost[i][a] > cost[i][b])
        return cost[i][b];
    else return cost[i][a];
}

void put(int i){
    cost[i][0]=info[i][0]+min(i-1, 1, 2);
    cost[i][1]=info[i][1]+min(i-1, 0, 2);
    cost[i][2]=info[i][2]+min(i-1, 0, 1);
}


int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> info[i][0] >> info[i][1] >> info[i][2];
    }

    cost[0][0]=info[0][0];
    cost[0][1]=info[0][1];
    cost[0][2]=info[0][2];


    for(int i=0;i<n;i++){
        put(i);
    }

    if(cost[n-1][0]>=cost[n-1][1] && cost[n-1][2] >= cost[n-1][1]){
        cout << cost[n-1][1];
    }else if(cost[n-1][0]>=cost[n-1][2] && cost[n-1][1] >= cost[n-1][2]){
        cout << cost[n-1][2];
    }else{ 
        cout << cost[n-1][0];
    }
}   
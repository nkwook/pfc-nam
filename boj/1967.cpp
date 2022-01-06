#include <iostream>
using namespace std;
#include <vector>

// not binary tree...
// idea: to save max of half way of tree / save entire subtree sum val
// also use 2nd biggest path to eval max of tree

vector<int> child[10001];
int weight [10001]={};
int diameter[10001][2];
int n, a, b, w;

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

void dfs(int x){
    int max1=0;
    int max2=0;
    int tmp=0;
    int localMax=0;
    for(int i: child[x]){
        dfs(i);
        tmp=diameter[i][0]+weight[i]; 
        if(tmp > max2){
            max2=tmp;
        }
        if(max2>max1){
            tmp=max2;
            max2=max1;
            max1=tmp;
        }
        
        if(diameter[i][1]==0){
            diameter[i][1]=weight[i];
        }
        else if (diameter[i][1]>localMax){
            localMax=diameter[i][1];
        }
    }
    diameter[x][0]=max1;
    localMax=max(localMax,max1+max2);
    diameter[x][1]=localMax;

    return;
}

int main(){
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b >> w;
        child[a].push_back(b);
        weight[b]=w;                
    }

    dfs(1);
    int result=diameter[1][1];    
    
    cout << result;
    return 0;

}
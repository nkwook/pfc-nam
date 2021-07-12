#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first;
#define Y second;
/*
    Need to watch out for negative index of arr
*/

int main(){
    int n, k;
    cin >> n >> k;

    int vis[1000001]={};

    queue<pair<int, int>> Q;

    Q.push({n, 0});
    vis[n]=1;

    while(!Q.empty()){
        int x=Q.front().X;
        int y=Q.front().Y;
        Q.pop();

        if(x==k){
           cout << y;
           return 0; 
        }

        int x1=2*x;
        int x2=x+1;
        int x3=x-1;

        if(x1<200000 && !vis[x1]){
            Q.push({x1, y+1});
            vis[x1]=1;
        } 

        if(!vis[x2]){
            Q.push({x2, y+1});
            vis[x2]=1;
        }

        if(x3>=0 && !vis[x3]){
            Q.push({x3, y+1});
            vis[x3]=1;
        }


    }


}
#include <iostream>
using namespace std;
#include <queue>
#include <utility>

queue<int > Q;
int vis[1000002]={};

int main(){
    int f, s, g, u , d;
    cin >> f >> s >> g >> u >> d;

    Q.push(s);
    vis[s]=1; //to avoid confusion with 0

    while(!Q.empty()){
        int x=Q.front();
        Q.pop();

        if(x==g){
            cout << vis[x]-1;
            return 0;
        }

        if(x+u <=f && vis[x+u]==0){
            Q.push(x+u);
            vis[x+u]=vis[x]+1;
        }

        if(x-d >=1 && vis[x-d]==0){
            Q.push(x-d);
            vis[x-d]=vis[x]+1;
        }
    }

    cout << "use the stairs";


}
#include <iostream>
using namespace std;
#include <queue>

// vector<int> adj[10001];
int lc[10001]={};
int rc[10001]={};
int level[10001]={};
int lPos[10001]={};
int rPos[10001]={};
int n;
int node, ln, rn;
int rootNum=-1;
int cnt=0;
int position=0;
queue<int> Q;
int maxWidth=1;
int maxWidthLevel=10001;

void findRoot(int x){
    cnt++;
    if(lc[x]!=-1){
        findRoot(lc[x]);
    }
    if(rc[x]!=-1){
        findRoot(rc[x]);
    }
    return;
}

void getLevel(){
    while(!Q.empty()){
        int front=Q.front();
        Q.pop();
        int l=lc[front];
        int r=rc[front];
        if(l!=-1){
            level[l]=level[front]+1; 
            Q.push(l);
        }
        if(r!=-1){
            level[r]=level[front]+1;
            Q.push(r);
        }
    }
    return;
}

void inOrder(int x){
    if(lc[x]!=-1)  inOrder(lc[x]);
    position++;

    int nodeLevel=level[x];
    if(lPos[nodeLevel]==0){
        lPos[nodeLevel]=position;
    }else{
        rPos[nodeLevel]=position;
        int w=rPos[nodeLevel]-lPos[nodeLevel]+1;
        if(w>maxWidth){
            maxWidth=w;
            maxWidthLevel=nodeLevel;
        }else if(w==maxWidth){
            if(maxWidthLevel > nodeLevel) maxWidthLevel=nodeLevel;
        }
    }

    if(rc[x]!=-1) inOrder(rc[x]);
    return;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> node >> ln >> rn;
        lc[node]=ln;
        rc[node]=rn;    
     }

    for(int i=1;i<=n;i++){
        findRoot(i);
        if(cnt==n){
            rootNum=i;
            break;
        }
        cnt=0;
    }

    Q.push(rootNum);
    level[rootNum]=1;
    getLevel();

    inOrder(rootNum);

    if(maxWidthLevel==10001) {
        maxWidthLevel=1;
    }
    cout << maxWidthLevel << " " <<maxWidth;
    return 0;

}
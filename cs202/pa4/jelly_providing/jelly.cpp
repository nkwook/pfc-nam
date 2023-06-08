#include "jelly.h"
using namespace std;
#include <iostream>
#include <vector>

int queryCnt=0;
int neightbors[1001][1001];
vector<int> result;
bool vis[1001];

std::vector<int> start(int N)
{
    for (int i=0;i<N;i++){
        vis[i]=false;
    }
    std::vector<int> E;
    result.push_back(1);
    int current=1;
    vis[1]=true;
    E.push_back(current);
    while(E.size() < N){
        for (int i=1;i<=N;i++){
            if(vis[i]) continue;
            E.push_back(i);
            if(query(E)==1){
                vis[i]=true;
                break;
            }
            E.pop_back();
        }
    }
    return E;
}
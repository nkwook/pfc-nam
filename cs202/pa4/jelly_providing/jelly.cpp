#include "jelly.h"
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

vector<int> result;

void getEndPoints(int start, int end, vector<int>& target, int numOfEnds){

    auto first = target.begin() + start;
    auto last = target.begin() + end + 1;
    cout << "call with " <<start << ' ' << end << ' ' << numOfEnds << '\n';
    vector<int> includeQuery(first, last);

    int includeQueryResult=query(includeQuery);
    // cout << "include query with: ";
    // for(auto iq: includeQuery ){
    //     cout << iq << " " ;
    // }
    // cout << '\n';

    // cout << "result: " << includeQueryResult << '\n';
    vector<int> excludeQuery(target.begin(), first);
    vector<int> q2(last, target.end());
    excludeQuery.insert(excludeQuery.end(), q2.begin(), q2.end());
    // cout << "exclude query with: ";
    // for(auto iq: excludeQuery ){
    //     cout << iq << " " ;
    // }
    // cout << '\n';

    int excludeQueryResult=query(excludeQuery);
    // cout << "result: " <<  excludeQueryResult << '\n';
    
    int mid=(start+ end)/2;    
    if(includeQueryResult > excludeQueryResult){
        if(end-start==1){
            result.push_back(target[start]);
            result.push_back(target[end]);
            return;
        }
        getEndPoints(start, mid, target, 2);
        getEndPoints(mid+1, end, target, 2);
    }else if(includeQueryResult == excludeQueryResult){
        if(start == end){
            result.push_back(target[start]);
            return;
        }
        getEndPoints(start, mid, target, 1);
        getEndPoints(mid+1, end, target, 1);
    }

    return;
}

std::vector<int> start(int N)
{
    int start=1;
    int end=N;
    vector<int> E;
    if(N==1){
        E.push_back(1);
        return E;
    }
    vector<int> vStart, vEnd;
    bool vis[N+1];
    for (int i=0;i<=N;i++){
        vis[i]=false;
    }

    vector<int> target;
    for (int i=1;i<=N;i++){
        target.push_back(i);
    }
    while(target.size()!=0){

        getEndPoints(0, target.size()-1, target, 2);
        cout << "result!: " ;
        for (auto r :result){
            vis[r]=true;
            cout << r << ' ' ;
        }
        cout  << '\n';

        if (vStart.empty()){
            vStart.push_back(result[0]);
            vEnd.push_back(result[1]);
        }else{
            vector<int> orderQuery= {vStart[vStart.size()-1], result[0]};
            int orderQueryResult=query(orderQuery);
            if(orderQueryResult==2){
                vStart.push_back(result[1]);
                vEnd.push_back(result[0]);
            }else if(orderQueryResult ==1){
                vStart.push_back(result[0]);
                vEnd.push_back(result[1]);
            }else{
                cout << "should not be here " << orderQueryResult;
                return E;
            }

        }
        result.clear();
        target.clear();
        for(int i=1; i<=N;i++){
            if (vis[i]) continue;
            target.push_back(i);
        }
        // cout << "next target: ";
        // for (auto t: target){
        //     cout << t << ' ';
        // }
        // cout  << '\n';
        if(target.size()==1){
            vStart.push_back(target[0]);
            break;
        }
    }
    reverse(vEnd.begin(), vEnd.end());
    vStart.insert(vStart.end(), vEnd.begin(), vEnd.end());
    // cout << "vStart: ";
    // for (auto v: vStart){
    //     cout << v << " ";
    // }
    // cout << "\nvEnd: ";
    // for (auto v: vEnd){
    //     cout << v << " ";
    // }
    return vStart;
}

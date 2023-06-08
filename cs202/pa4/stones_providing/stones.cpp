#include "stones.h"
using namespace std;
#include <iostream>
#include <vector>



void stones(int N)
{

    std::vector<int> v1, v2;
    // 1 나왔던 것들 + 정답인 것들 다 배제 
    bool heavyStones[N+1];
    for (int i=0;i<=N;i++){
        heavyStones[i]=false;
    }

    vector<int> largeVec;
    vector<int> smallVec;

    for(int i=1;i<=N/2;i++){
        int a=2*i-1;
        int b=2*i;
        int cmpResult=compare(a, b);
        if (cmpResult==1){
            largeVec.push_back(a);
            smallVec.push_back(b);
        }else if(cmpResult==-1){
            largeVec.push_back(b);
            smallVec.push_back(a);
        }else{
            largeVec.push_back(a);
            largeVec.push_back(b);
            smallVec.push_back(a);
            smallVec.push_back(b);
        }
    }
    if (N %2 ==1){
        largeVec.push_back(N);
        smallVec.push_back(N);
    }

    cout << "smallvec: " ;
    for (auto i: smallVec){
        cout << i <<' ';
    }
    cout << '\n' << "largeVec: ";
    for (auto i: largeVec){
        cout << i <<' ';
    }
    cout  << '\n';
    // largeVec.size() << ' ' << smallVec.size() << '\n';
    int maxIdx=largeVec[0];
    v1.push_back(maxIdx);
    for(int i=1;i<largeVec.size();i++){
        int currIdx=largeVec[i];
        int cmpResult=compare(maxIdx, currIdx);
        if(cmpResult==1){
            heavyStones[maxIdx]=true;
        }else if (cmpResult==-1){
            heavyStones[currIdx]=true;
            v1.clear();
            v1.push_back(currIdx);
            maxIdx=currIdx;
        }else{
            v1.push_back(currIdx);
        }
    }    

    if(v1.size() == N){
        v2=v1;
        answer(v1, v2);
        return;
    }

    for(int maxIdx: v1){
        heavyStones[maxIdx]=true;
    }

    int curvecIdx=-1;
    for(int i=0;i<smallVec.size();i++){
        if(!heavyStones[smallVec[i]]){
            curvecIdx=i;
            break;
        }
    }



    int minIdx=smallVec[curvecIdx];
    v2.push_back(minIdx);
    curvecIdx++;
    while(curvecIdx < smallVec.size()){
        int curIdx=smallVec[curvecIdx];
        if (heavyStones[curIdx]){
            cout << curIdx << " filtered \n";
            curvecIdx++;
            continue;
        }

        int cmpResult=compare(minIdx, curIdx);
        cout << minIdx << ' ' << curIdx << ' ' << cmpResult  << '\n';
        if(cmpResult==1){
            minIdx=curIdx;
            v2.clear();
            v2.push_back(minIdx);
        }else if(cmpResult==0){
            v2.push_back(curIdx);
        }
        curvecIdx++;
    }


    cout << "v2: ";
    for (auto i: v1){
        cout << i <<' ';
    }
    cout << '\n' << "v1: ";
    for (auto i: v2){
        cout << i <<' ';
    }
    cout << '\n';

    answer(v2, v1);

    
}

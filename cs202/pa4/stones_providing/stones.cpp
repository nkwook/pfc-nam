#include "stones.h"
using namespace std;
#include <iostream>

int segmentTree[601];
int cmpCount=0;

int makeMinTree(int idx, int startIdx, int endIdx){
    if(startIdx==endIdx ){
        return startIdx;
    }
    int midIdx=(startIdx+endIdx)/2;
    int leftChild=makeMinTree(idx*2, startIdx, midIdx);
    int rightChild=makeMinTree(idx*2+1, midIdx+1, endIdx);
    // cout << idx << ' ' << startIdx << ' ' << endIdx << ' ' << leftChild << ' ' << rightChild << '\n';
    int cmpResult=compare(leftChild, rightChild);
    cmpCount++;
    int smallStone=leftChild;
    if(cmpResult==1){ // 왼쪽이 더 무거우면 1
        smallStone=rightChild;
    }
    // segmentTree[idx]=smallStone;
    return smallStone;
}


int makeMaxTree(int idx, int startIdx, int endIdx){
    if(startIdx==endIdx){
        return startIdx;
    }
    int midIdx=(startIdx+endIdx)/2;
    int leftChild=makeMaxTree(idx*2, startIdx, midIdx);
    int rightChild=makeMaxTree(idx*2+1, midIdx+1, endIdx);
    int cmpResult=compare(leftChild, rightChild);
    // cout << idx << ' ' << startIdx << ' ' << endIdx << ' ' << leftChild << ' ' << rightChild <<  ' ' << cmpResult << '\n';
    int bigStone=leftChild;
    if(cmpResult==-1){ // 오른쪽 더 무거우면 -1
        bigStone=rightChild;
    }
    cmpCount++;
    // segmentTree[idx]=bigStone;
    return bigStone;
}

void stones(int N)
{
    std::vector<int> v1, v2;
    int minResult=makeMinTree(1, 1, N);
    int maxResult=makeMaxTree(1, 1, N);
    // cout << "maxresult: " << maxResult <<'\n';

    for (int i=1;i<=N;i++){
        if (compare(minResult, i) ==0){
            v1.push_back(i);
        }
        if (compare(maxResult, i)==0){
            v2.push_back(i);
        }
    }

    // cout << "v1: ";
    // for (auto i: v1){
    //     cout << i <<' ';
    // }
    // cout << '\n' << "v2: ";
    // for (auto i: v2){
    //     cout << i <<' ';
    // }
    // cout << '\n';

    answer(v1, v2);

    

}

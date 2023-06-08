#include "bridge.h"
#include <vector>
using namespace std;
#include <iostream>

vector<pair<int,int>> result;

void find_bridges(int N)
{
    for (int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if (count_crosses(i, j)==-1){
                report_bridge(i, j);
            }
        }
    }
}

// // void search(int start){
// //     int base=check(start, start);

// //     int mid=(start+end)/2;
// //     if(start==mid){
// //         if (check(start, start)){

// //         }
// //     }

// // }
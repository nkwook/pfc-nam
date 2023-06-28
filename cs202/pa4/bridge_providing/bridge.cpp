#include "bridge.h"
#include <vector>
using namespace std;
#include <iostream>

vector<pair<int,int>> result;
int crossCounts[2][50001];
int numStartingPoints[2][50001]; 

void find_bridges(int N)
{
    cout << N << '\n';
    for (int i=1;i<=N;i++){
        if (i==1){
            int cnt=count_crosses(1, 1);
            crossCounts[0][1]=cnt;
            crossCounts[1][1]=cnt;
        }
        else if (i >= 2){
            crossCounts[0][i]=count_crosses(i, 1);   
            crossCounts[1][i]=count_crosses(1, i);
            for( int j=0;j<2;j++){
                if(crossCounts[j][i-1]==-1){
                    if (crossCounts[j][i]==-1){
                        numStartingPoints[j][i-1]=1;
                    }else{
                        numStartingPoints[j][i-1]=crossCounts[j][i] + 1;
                    }
                }else if(crossCounts[j][i]==-1){
                    numStartingPoints[j][i-1]=0;
                }
                else{
                    numStartingPoints[j][i-1]=crossCounts[j][i]-crossCounts[j][i-1];
                }
            }
        }
    }

    cout << "upper : ";
    for(int i=1;i<=N;i++){
        cout << numStartingPoints[0][i] << ' ' ;
    }

    cout  << "\nlower: ";
    for(int i=1;i<=N;i++){
        cout << numStartingPoints[1][i] << ' ' ;
    }
    cout << '\n';


    int upperPointer=1;
    int lowerPointer=1;
    bool terminate=false;
    while(upperPointer <= N && lowerPointer <=N){
        while(numStartingPoints[0][upperPointer] ==0){
            upperPointer ++;
            if (upperPointer > N){
                terminate=true;
                break;
            }
        }
        // 만나서 아래 point 찾기
        while(numStartingPoints[1][lowerPointer]==0){
            lowerPointer ++;
            if (lowerPointer > N){
                terminate=true;
                break;
            }
        }
        if(terminate){
            // 끝날때 경계조건 고려해야함
            break;
        }
        // pair 있음
        numStartingPoints[0][upperPointer]--;
        numStartingPoints[1][lowerPointer]--;
        cout << "got the bridge " << upperPointer << ' ' << lowerPointer << '\n';
        report_bridge(upperPointer, lowerPointer);
    }
    cout << "Fin condition: " << upperPointer << ' ' << numStartingPoints[0][upperPointer] << 
        ' ' <<lowerPointer <<  ' ' << numStartingPoints[1][lowerPointer]  << '\n';

    while (upperPointer == N+1 && lowerPointer <= N){
        if (numStartingPoints[1][lowerPointer]){
            cout << "got the bridge " << N << ' ' << lowerPointer << '\n';
            report_bridge(N, lowerPointer);
        }
        lowerPointer ++;
    }
    while(lowerPointer ==N+1 && upperPointer <=N){
        if (numStartingPoints[0][upperPointer]){
            cout << "got the bridge " << upperPointer << ' ' << N << '\n';
            report_bridge(upperPointer, N);
        }
        upperPointer++;
    }

    if(count_crosses(N, N)==-1){
        cout << "got the bridge " << N << ' ' << N << '\n';
        report_bridge(N, N);
    }

}

#include<iostream>
using namespace std;

int n, k;
int arr[101];
int multiTab[101];

// finding rule .... think more!
// especially in greedy problems.
// "갯수가 어쨌든 어차피 들어가야함. 그 후 똑같은 문제가 된다는 것을 기억하자"

int find(int start, int x){
    for(int i=start;i<k;i++){
        if(arr[i]==x){
            return i-start;
        }
    }
    return 1000;
}

int main(){
    cin >> n >> k;

    for(int i=0;i<n;i++){
        multiTab[i]=0;
    }

    int result=0;

    for(int i=0;i<k;i++){
        cin >> arr[i];
    }

    for(int i=0;i<k;i++){
        bool succeed=false;
        

        for(int j=0;j<n;j++){
            if(multiTab[j]==0 || multiTab[j]==arr[i]){
                multiTab[j]=arr[i];
                succeed=true;
                break;
            }
        }
        if(!succeed){
            int max=0;
            int maxIndex=0;
            for(int l=0;l<n;l++){
                int distance=find(i, multiTab[l]);
                // cout << l << " " << distance << '\n';
                if(distance>max){
                    max=distance;
                    maxIndex=l;
                }
            }
            multiTab[maxIndex]=arr[i];

            // cout <<  arr[i] << " " << maxIndex << " " <<multiTab[maxIndex] <<'\n';
            result++;

        }

    }

    cout << result;
    return 0;
}
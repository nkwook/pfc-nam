#include <iostream>
using namespace std;
#include <deque>


int init[20][20];
int temp[20][20];
int n;
deque<int> D;

int move(int dir){
    for(int i=0;i<n;i++){
        int comb=0;
        for(int j=0;j<n;j++){
            int vic=0;
            if(dir==0){
                vic=temp[i][n-j-1];
            }else if(dir==1){
                vic=temp[j][i];
            }else if(dir==2){
                vic=temp[i][j];
            }else{
                vic=temp[n-j-1][i];
            }

            if(vic){
                if(!D.empty() && D.front()==vic && comb==0){
                    D.pop_front();
                    D.push_front(2*vic);
                    comb=1;
                }else{
                    D.push_front(vic);
                    comb=0;
                }
            }
            
        }

        for(int j=0;j<n;j++){
            int put=0;
            if(!D.empty()){
                put=D.back();
                D.pop_back();
            }

            if(dir==0){
                temp[i][n-j-1]=put;
            }else if(dir==1){
                temp[j][i]=put;
            }else if(dir==2){
                temp[i][j]=put;
            }else{
                temp[n-j-1][i]=put;
            }
        }

    }
    return 0;
}


int main(){
    cin >> n;
    int max=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> init[i][j];
        }    
    }

    for(int k=0;k<1024;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]= init[i][j];
            }
        }

        int kdir=k;
        for(int l=0;l<5;l++){
            int dir=kdir%4;
            move(dir);
            kdir/=4;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j]>max){
                    max=temp[i][j];
                }
            }    
        }     
    }

    cout << max;
    // for(int i=0;i<n;i++){
    //     cout << '\n';
    //     for(int j=0;j<n;j++){
    //         cout << temp[i][j] <<' ';
    //     }    
    // }

    

}
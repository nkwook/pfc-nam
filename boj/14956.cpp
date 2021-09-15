#include <iostream>
using namespace std;
#include <utility>
#include <tuple>
#include <cmath>

int n, m;

int dx[4][4]={{0, 1, 1, 0}, 
            {0, 0, 1, 1}, 
            {1, 0, 0, 1}, 
            {1, 1, 0, 0}};

int dy[4][4]={{0, 0, 1, 1}, 
            {0, 1, 1, 0}, 
            {1, 1, 0, 0}, 
            {1, 0, 0, 1}};


pair<int, int> find(int n, int m, int o, int x, int y){
    // cout << n <<" " <<  m << " " << o << " " << x << " " << y <<'\n';
    if(n==1){
        m--;
        return make_pair(x+dx[o][m], y+dy[o][m]);
    }

    int quotient=m/n;
    int remainder=m%n;
    if(remainder==0){
        quotient--;
        remainder=n;
    } 

    int x2, y2;

    x2=x+sqrt(n)*dx[o][quotient];
    y2=y+sqrt(n)*dy[o][quotient];


    // if(quotient==0){
    //     o=()
    // }else if(quotient==3){

    // }


    if(o==1 || o==3){
        if(quotient==0){
            o=(o+3)%4;
        }else if(quotient==3){
            o=(o+1)%4;
        }
    }else if(o==0 || o==2){
        if(quotient==0){
            o=(o+1)%4;
        }else if(quotient== 3){
            o=(o+3)%4;
        }
    }
    
    return find(n/4, remainder, o, x2, y2); // coordinates
}



int main(){
    cin >> n >> m;

    pair<int, int> p=find(n*n/4, m, 1, 1, 1);
    cout << p.first << " " << p.second;

}
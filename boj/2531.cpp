#include<iostream>
using namespace std;

int n, d, k, c;
int temp;

int sushi[3003001];
int cnt[3001]={};
int cur=0;

int add(int x){
    cnt[x]++;
    if(cnt[x]==1 && x!=c){
        // cout << x << ' ' << cur << '\n';
        cur++;
    }
    return cur;
}

int sub(int x){
    cnt[x]--;
    if(cnt[x]==0 && x!=c){
        //  cout << x << ' ' << cur << '\n';

        cur --;
    }
    return cur;
}

int main(){
    cin >> n >> d >> k >> c;
    int max=0;

    for(int i=0;i<n;i++){
        cin >> temp;
        if(i<k){
            sushi[n+i]=temp;
        }
        sushi[i]=temp;
    }

    // int p1=0;
    // int p2=3;
    for(int i=0;i<k;i++){
        add(sushi[i]);
    }
    max=cur;

    for(int i=k;i<n+k;i++){
        add(sushi[i]);
        sub(sushi[i-k]);
        if(cur>max){
            max=cur;
        }
    }
    cout << max+1;

}
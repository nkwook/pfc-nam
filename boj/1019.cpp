#include <iostream>
using namespace std;
#include <math.h>
#include <utility>
#include <vector>

int n;
vector< pair<int, int> > v;
int result[10]={};

int digits(int num){
    int dig=0;
    while(num>0){
        dig++;
        num/=10;
    }
    return dig;
}

int main(){
    cin >> n;
    int temp=n;
    int cnt=digits(n);

    v.push_back({0, 1});
    for(int i=1;i<=cnt;i++){
        v.push_back({v[i-1].first+v[i-1].second*9, (i+1)*pow(10, i)});
    }
    
    if(cnt==1){
        for(int i=1;i<=n;i++){
            result[i]++;
        }
        for(int i=0;i<10;i++){
            cout << result[i] <<" ";
        }
        return 0;
    }

    for(int i=0;i<10;i++){
        if(i==0) result[i]+=v[cnt-2].first;
        else result[i]+=v[cnt-2].second;
    }
    int cur=pow(10, cnt-1);
    int subdig=cnt;
    while(true){
        int sub=n-cur;
        int newdig=digits(sub);
        // cout <<result[9] << ' ' << cur << '\n';
        if(subdig>newdig){ //자릿수 변화- sub개만큼 전 숫자들을 더해줘야함
            for(int i=subdig;i>newdig;i--){
                int curfront=((int)(cur/pow(10, i-1)))%10;
                result[curfront]+=sub+1;     
                if(i==1){ //newdig==0
                    for(int i=0;i<10;i++){
                    cout << result[i] <<" ";
                    }
                    return 0; 
                }
            }
            subdig=newdig;
        }
       if(newdig<=1){
            for(int i=0;i<=sub;i++){
                result[i]++;
            }
     
            for(int i=0;i<10;i++){
                cout << result[i] <<" ";
            }
            return 0;
        }
        
        int curfront=((int)(cur/pow(10, subdig-1)))%10;
        for(int i=0;i<10;i++){
            if(i==curfront){ // 999 다 있을경우
                result[i]+=pow(10, newdig-1);
            } 
            result[i]+=v[subdig-2].second;

        }
        cur+=pow(10, subdig-1);
    }    

    return 0;
}

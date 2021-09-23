#include <iostream>
using namespace std;
#include <vector>

int n, m;
// vector<int > v;
bool broken[10];
vector <int> buttons;
int ans=0;

int diff(int a, int b){
    int result=a-b;
    if(result<0) result*=-1;
    return result;
}

int det(int x){
    if(!x){
        for(int i:buttons){
            if(i==x){
                return 1;
            }
        }
        return 0;
    }
    int flag=1;
    while(x && flag){
        int y=x%10;
        x/=10;
        flag=0;
        for(int i:buttons){
            if(i==y){
                flag=1;
                break;
            }
        }
    }
    return flag;

}

int main(){
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        // v.push_back(x); 
        broken[x]=true;
    }

    for(int i=0;i<=9;i++){
        if(broken[i]) continue; //using index
        buttons.push_back(i);
    }

    if(!buttons.size()){
        cout << diff(n, 100);
        return 0;
    }      

    int min=9999999;
    int t=0;
    for(int i=0;i<2*n+10;i++){
        if(!det(i)) continue;
        if(diff(n, i)<min){
            // cout  << ">" << i <<'\n';
            min=diff(n, i);
            t=i;
        }
        // cout << t << '\n';
    }
    int tc=t;
    int presses=0;
    while(tc){
        tc/=10;
        presses++;
    }
    if(!t){
        presses=1;
    }

    if(n==0){
        for(int i:buttons){
            if(i==0){
                cout << 1;
                return 0;
            }
        }
        int min=999;
        for(int i:buttons){
            if(min>i){
                // t=i;
                min=i;
            }
        }
        cout << 1+min;
        return 0;
    }

    
    ans= presses+diff(n, t);
    if(ans> diff(n,100)){
        ans=diff(n,100);
    }
    cout << ans;


    return 0;


}
#include <iostream>
using namespace std;
#include <queue>

int n;
int x;

class cmp{
    public:
        bool operator()(int a, int b){
            if(abs(a)!=abs(b)) return abs(a) > abs(b);
            else return a > 0 ;
        }
};

priority_queue<int, vector<int>, cmp> pq;


int main(){    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    while(n--){
        cin >>x;
        if(x==0){
            if(pq.empty()){
                cout << 0 << '\n';
            }else{
                cout << pq.top() <<'\n';
                pq.pop();
            }
        }else{
            pq.push(x);
        }
    }

}


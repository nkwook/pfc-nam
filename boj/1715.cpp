#include <iostream>
using namespace std;
#include <queue>

// need to think more...............
// also need consider data type

class cmp{
    public:
        bool operator()(int a, int b){
            return a>b;
        }
};

priority_queue<int, vector<int>, cmp> pq;
int n, x;

int main(){
    cin >> n;
    while(n--){
        cin >> x;
        pq.push(x);
    }

    int result=0;
    int first=0;
    int second=0;

    while(pq.size()>1){
        first=pq.top();
        pq.pop();
        second=pq.top();
        pq.pop();

        result+=(first+second);
        pq.push(first+second);
    }
    cout << result;


}
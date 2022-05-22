#include<iostream>
#include <vector>
using namespace std;

int n;
int seq[1000001];
vector<int> v;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> seq[i];
    }

    for(int i=0;i<n;i++){
        vector<int>::iterator low=lower_bound(v.begin(), v.end(), seq[i]);
        // 여기서 v.size()-1하면 unsigned int이기 때문에 -1이 아니라 큰 수 뜬다.
        if(low-v.begin()> v.size()){
            v.push_back(seq[i]);
        }
        else{
            v[low-v.begin()]=seq[i];
        }
    }
    cout << v.size();

}



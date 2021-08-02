#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<long long> num;

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        long long a;
        cin >> a;
        num.push_back(a);
    }

    sort(num.begin(), num.end());

    long long result=num[0];
    int max=0;
    int cnt=0;

    for(int i=0;i<n-1;i++){
        if(num[i]==num[i+1]){
            cnt++;
            if(cnt > max){
                max=cnt;
                result=num[i];
            }
        }else{
            if(cnt>max){
                max=cnt;
            }
            cnt=0;
        }
    }

    cout << result;




}
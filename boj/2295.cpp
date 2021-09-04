#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int n;
int u[1001];
vector<int> twosum;

int bsearch(int t, int z){
    // this returns same or bigger close num
    int r=lower_bound(twosum.begin(), twosum.end(), t)- twosum.begin();
    // cout << r << '\n';
    if(twosum[r]==t){
        // cout << t << " " << twosum[r] << '\n';
        return twosum[r]+z;
    }else{
        return 0;
    } 

}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> u[i];
    }


    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            twosum.push_back(u[i]+u[j]);
        }

    }

    sort(twosum.begin(), twosum.end());

    int max=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int b= bsearch(u[j]-u[i], u[i]) ;
            if(b>max){
                max=b;
            }    
            
        }
    }

    cout << max;



}
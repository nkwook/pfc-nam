#include <iostream>
using namespace std;
#include <vector>

int n;
int arr[4000001];
vector<int> prime;

int main(){
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        arr[i]=i;
    }

    for(int i=2;i*i <=n;i++){
        if(arr[i]==0) continue;
        int j=i+i;
        while(j<=n){
            arr[j]=0;
            j+=i;
        }
    }
    
    for (int i = 2; i <=n; i++)
    {
        if(arr[i]){
            prime.push_back(i);
        }
    }

    int sum=0;
    int result=0;
    int j=0;
    for(int i=0;i<prime.size();i++){
        while(sum<n && prime.size()>j){
            sum+=prime[j];
            j++;
        }
        if(sum==n){
            result++;
        }
        if(sum>=n){
            sum-=prime[i];
        }
    }

    cout << result;

    
    return 0;


}
#include<iostream>
using namespace std;
#include <set>

int n, a;
long long b;
multiset<long long, greater<long>> candy;



int main(){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
	
    cin >> n;
    while(n--){
        cin >> a >> b;

        if(a==1){
            candy.insert(b);
        }else if(a==2){
            if (candy.empty()){
                continue;
            }
            
            if(b==1){
                candy.erase(candy.begin());
            }else if(b==-1){
                candy.erase(--candy.end());
            }
        }else if(a==3){
            if(candy.empty()){
                cout << "EMPTY";
            }
            else if(b==1){
                cout << *candy.begin();
            }else if(b==-1){
                cout << *(--candy.end());
            }
            cout << " ";
        }


    }
    return 0;
}
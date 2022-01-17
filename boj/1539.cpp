#include <iostream>
using namespace std;
#include <map>

/*
    By make a tree, worst case goes to n square....
    needed to reduce to nlgn
    inorder traversal!!!! 
    using map and lowerbound!!!
    also first elem corresponds to m.begin iter
*/


map<int, int> m;
int n;
int p;

int main(){
    cin >> n;
    long long result=0;
    int height=0;
    for(int i=0;i<n;i++){
        cin >> p;
        auto it=m.lower_bound(p);        
        if(i==0){
            height=0;
        }
        else if(it==m.end()){
            it--;
            height=it->second;
        }else {
            height=it->second;
            
            if(it!=m.begin()){
                it--;
                if(height < it->second){
                    height=it->second;
                }
            }
        }
        m[p]=height+1;
        result+=height+1;
     
    }

    cout << result;


}
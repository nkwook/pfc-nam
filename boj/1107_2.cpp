#include <iostream>
using namespace std;
#include <vector>

/* should not consider exceptions from first step
using arrays for this kind of repeating problems
also using return value !!
 
*/

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

// returning length
int det(int x){
    if(!x){
        if(broken[x]){
            return 0;
        }
        return 1;
    }
    // int flag=1;
    int len=0;
    while(x){
        if(broken[x%10]) return 0;
        x/=10;
        len++;
    }
    return len;
}

int main(){
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        // v.push_back(x); 
        broken[x]=true;
    }


    int min=diff(n, 100);
    int t=0;
    for(int i=0;i<2*n+10;i++){
        int d=det(i);
        if(!d) continue;
        if(diff(n, i)+d<min){
            // cout  << ">" << i <<'\n';
            min=diff(n, i)+d;
            t=i;
        }
        // cout << t << '\n';
    }
    cout << min;
    return 0;


}
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        int selection[n];
        int result[n];
        int vis[n];
        int count[n];
        for(int i=0;i<n;i++){
            cin >> selection[i];
            result[i]=0;
        }

        // cout << "FF";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                count[j]=0;
            }

            if(result[i]) continue;

            int next=i;
            if(result[next]) continue;
            stack<int> S;

            while(true){

                count[next]++;
                next=selection[next]-1;
         
                if(count[next]>1){ //clear
                    result[next]=1;
                    while(selection[next]-1!=next){
                        result[next]=1;
                        next=selection[next]-1;
                    }
                    S.pop();
                    cout << S.size() << "\n";
                    // while(!S.empty()){
                    //     // cout << S.top() << ",";
                    //     result[S.top()]=-1;
                    //     S.pop();
                    // }
                    break;
                }
                S.push(next);
                // cout << next << ",,,";

            }
        }

        // cout << "\n";
        int ans=0;
        // cout << '\n';
        for( int i=0;i<n;i++){
            // cout << result[i] << ",";
            if(result[i]<1) ans++;
        }
        cout << ans << '\n';
    }



}
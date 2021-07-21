#include <iostream>
#include <stack>
#include <utility>
using namespace std;

const int VISITED=1;
const int CYCLE=2;
const int NOTCYCLE=3;

/*
    느낀점
    1. 케이스를 확실하게 분리해야.
     result든 count든 vis든 표시 배열을 남발하는 것 보다, state를 define하여 분류해주는게 편함
     (하나의 조건문 안에서 처리할 수 있다는 면에서)
    +) 배열 초기화 불필요하게 하는 것 보다 state 넣어주는게 낫다. 불필요한 초기화로 시간 초과 .
    ++) 각 그룹의 숫자 직접 넣어주는 방법.
    2. for loop 인덱스도 저장소로서의 의미를 가질 수 있음. 시작점 몰라서 stack 사용하고 그랬는데,
    그냥 cur에 가져다가 쓰면 되는거였음. 
    3. 디버깅 포인트 잘 찾기 
    
    더 좋은 풀이: 해당 시작 사람의 넘버 넣어서... 
    그냥 0아니면 ... 와우  
*/
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int selection[n+1];
        int state[n+1];
        // int count[n];
        
        // cout << "FFe";

        for(int j=1;j<=n;j++){
         
            cin >> selection[j];

            state[j]=0;
        }
        for(int i=1;i<=n;i++){
            int cur=i;
            // cout << cur;
            if(state[cur] >1) continue;
            while(true){
                state[cur]=VISITED;
                cur= selection[cur];

                if(state[cur]==CYCLE || state[cur]==NOTCYCLE){ 
                    // int t=S.top();
                    int cur=i;
                    while(state[cur]==VISITED){
                        state[cur]=NOTCYCLE;
                        cur=selection[cur];
                    }
                    break;
                }
                else if(state[cur]==VISITED && cur!=i){
                    while(state[cur]!=CYCLE){
                        state[cur]=CYCLE;
                        cur=selection[cur];
                    }
                    cur=i;
                    while(state[cur]!=CYCLE){
                        state[cur]=NOTCYCLE;
                        cur=selection[cur];
                    }
                    break;
                }else if(state[cur]==VISITED && cur ==i){
                    while(state[cur]!=CYCLE){
                        state[cur]=CYCLE;
                        
                        cur=selection[cur];
                        
                    }
                    break;
                }

            }
        }

        int ans=n;
        for( int i=1;i<=n;i++){
            // cout << state[i] << " ";
            if(state[i]==CYCLE) ans--;
        }
        cout << ans << '\n';

    }

}
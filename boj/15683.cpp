#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, m;
int room[10][10]; //?
int roomC[10][10];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

vector<pair<int, int> > cctv;
// list<struct cctv> slist; using this => we have to make too many  lists.
// 4^k method(4's notation) + using other array to store values
// not just adding other big container
// thinking about where to iterate and call functions.


void watch(int x, int y, int dir){
    int nx=x;
    int ny=y;
    while(true){
        nx=nx+dx[dir];
        ny=ny+dy[dir];
        if(0 > nx || nx >=n || 0>ny || ny>=m) break;;
        if(room[nx][ny]==6) break;

        roomC[nx][ny]=-1;

    }
    return;
}

int main(){
    int result=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin >> num;
            room[i][j]=num;
            if(num>0 && num <6){
                cctv.push_back(make_pair(i, j));
            }else if(num==0){
                result++;
            }
        }
    }   

    int cnt=1<<(2*cctv.size());

    for(int i=0;i<cnt;i++){
        int tmp=i;
        for(int s=0;s<n;s++){
            for(int t=0;t<m;t++){
                roomC[s][t]=room[s][t];
            }
        }
        
        for(int j=0;j<cctv.size();j++){
        
            int x=cctv[j].first;
            int y=cctv[j].second;

            int dir=tmp%4;
            tmp=tmp/4;
            // cout << x<< " " <<  y << '\n';
            // cout << "dir: " <<dir << " " << room[x][y] << '\n';

            switch(room[x][y]){
                case 1:
                    watch(x, y, dir);
                    break;
                case 2: 
                    watch(x, y, dir);
                    watch(x, y, (dir+2)%4);
                    break;
                case 3: 
                    watch(x, y, dir);
                    watch(x, y, (dir+3)%4);
                    break;
                case 4:
                    watch(x, y, dir);
                    watch(x, y, (dir+2)%4);
                    watch(x, y, (dir+3)%4);
                    break;
                case 5:
                    watch(x, y, dir);
                    watch(x, y, (dir+1)%4);
                    watch(x, y, (dir+2)%4);
                    watch(x, y, (dir+3)%4);
                    break;
                default:
                    break;
                
            }
        }

        int size=0;
        for(int s=0;s<n;s++){
            for(int t=0;t<m;t++){
                // cout << roomC[s][t] << " ";
                if(roomC[s][t]==0){
                    size++;
                }
            }
            // cout << '\n';
        }

        // cout << size << '\n';
        if(result>size) result=size;
        
    }

    cout << result;


}


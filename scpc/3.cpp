#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>

using namespace std;
vector<int> edges[501];
queue<pair<int, int> > Q;

set<int> box;

string Answer;

int detect(int x, int y){
    box.insert(y);
    for(int i=0;i<edges[y].size();i++){
        int next=edges[y][i];
        // cout << y << ' ' << next << '\n' ;
        if(next==x){
            return 1;
        }
        if(box.find(next) != box.end()){
            // cout << "???\n";
            continue;
        }
        box.insert(next);
        if(detect(x, next)){
            // box.clear();
            return 1;
        }
    }
    // box.erase(y);
    return 0;
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{           
        box.clear();

		Answer ="";
        int n, m, k;
        cin >> n >> m >> k;

        for(int i=0;i<=n;i++){
            edges[i].clear();
        }
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
        }
        for(int i=0;i<k;i++){
            int a, b;
            cin >> a >> b;
            pair<int, int> p=make_pair(a, b);
            Q.push(p);
            // Q.push({a, b});
        }

        while(!Q.empty()){
            int x=Q.front().first;
            int y=Q.front().second;
            Q.pop();
            edges[x].push_back(y);
            box.clear();
            if(detect(x, y)){
                Answer+='1';
                edges[x].pop_back();
                edges[y].push_back(x);
            }else{
                Answer+='0';
            }
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
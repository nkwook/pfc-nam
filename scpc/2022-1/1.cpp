#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Answer;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.first > b.first) return false;
    else if( a.first < b.first) return true;
    else {
        return a.second < b.second;
    }
    return false;
} 

int main(int argc, char** argv)
{
	int T, test_case;
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n;
        cin >> n;
        vector< pair<int, int>> v;
        vector<int> pos;
        int p;
        for(int i=0;i<n;i++){
            cin >> p;
            v.push_back({0, p});
            pos.push_back(p);
        }
        for(int i=0;i<n;i++){
            cin >> v[i].first;
        }
        sort(v.begin(), v.end(), cmp);
        // sort(pos.begin(), pos.end());
        
		
        Answer = 0;
        for(int i=0;i<n;i++){
            Answer+=abs(pos[i]-v[i].second);
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
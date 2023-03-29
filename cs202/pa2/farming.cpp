#include <iostream>
using namespace std;
#include <set>
#include<vector>
#include <map>

int n, w;

multiset <int> S;
map<int, vector<int>> pumps;
vector<tuple<int, int, int>> result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, l, p;
    
    cin >> n >> w;
    while(n--){
        cin >> x >> l >> p;

        pumps[x-l].push_back(p);
        pumps[l+x].push_back(-p);
    }

    int start=0;
    int end=0;
    int value=0;

    for(auto it=pumps.begin();it!=pumps.end();it++){

        int pos=it->first;
        // cout << pos << ", "; 
        vector<int> v=it->second;
        for(int i: v){
            if(i>0){
                S.insert(i);
            }else{

                auto target=S.find(-i);
                S.erase(target);
            }
        }

        int newValue;
        if(S.empty()){ //should not be here...
            newValue=0;
        }else{
            newValue=*S.rbegin();
        }
        // cout << "max: " << *S.rbegin() << '\n';
        if(newValue!=value){
            if(pos==0){
                value=newValue;
                continue;
            }
            end=pos;
            result.push_back({start, end, value});
            value=newValue;
            start=end;
        }
    }

    //last shot
    if(end!=w){
        result.push_back({end, w, 0});
    }

    cout << result.size() << '\n';
    for (auto t : result){
        cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << '\n';
    }
    return 0;

}
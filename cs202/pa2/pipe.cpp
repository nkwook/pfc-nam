#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

int n, a, b;
map<int, pair<int, int>> pipes;
map<int, tuple<int, int, int>> boundaries;

vector<string> result;


string make_result_string(string lp, string start, string end, string rp){
    return lp + start + ", " + end + rp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int lastPos=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        pipes[a].first++;
        pipes[b].second++;
        lastPos=b;
    }

    int num=0;
    for(auto p: pipes){
        int pos=p.first;
        int openCnt= p.second.first;
        int closeCnt= p.second.second;

        tuple<int, int, int> t;
        get<0>(t) =num;
        num+=openCnt;
        get<1>(t) = num;
        num-=closeCnt;
        get<2> (t)=num;
        boundaries[pos]=t;
    }

    string start="-";
    string end="+";
    string leftParenthesis="(";
    string rightParenthesis=")";
    bool isInterval=true;
    int intervalValue=0;
    if(boundaries.empty()){
        cout << "(-, +)";
        return 0;
    }

    for(auto it=boundaries.begin();it!= boundaries.end();it++){
        int pos=it->first;
        tuple<int, int, int> numPipesTuple=it->second;
        int beforePoints=get<0>(numPipesTuple);
        int pointPoints=get<1>(numPipesTuple);
        int afterPoints=get<2>(numPipesTuple);
        
        if(isInterval){ // beforePoint는 무조건 짝수임
            if(pointPoints%2){ // 구간 끝 , ')'
                end=to_string(pos);
                result.push_back(make_result_string(leftParenthesis, start, end, ")"));
                // afterPoints가 새 구간을 생성
                if(afterPoints%2==0){
                    isInterval=true;
                    leftParenthesis="(";
                    start=to_string(pos);
                }else{
                    isInterval=false;
                }
            }else if (afterPoints%2){ // 구간 끝, ']'
                end=to_string(pos);
                result.push_back(make_result_string(leftParenthesis, start, end, "]"));  
                isInterval=false;
                // 다시 구간 시작: 안될듯

            }
        }else{ // beforePoint는 무조건 홀수임
            if(pointPoints%2==0){ // 구간 시작, '['
                isInterval=true;
                leftParenthesis="[";
                start=to_string(pos);
                if(afterPoints%2==1){ // 점 구간
                    isInterval=false;
                    result.push_back(make_result_string("<", to_string(pos), to_string(pos), ">"));
                }else{
                    
                }
            } else if(afterPoints %2==0){ // 구간 시작, '('
                isInterval=true;
                leftParenthesis="(";
                start=to_string(pos);
            } 
        }
    }

    // 마지막 구간
    string temp="";
    if(isInterval){
        temp=start;
    }else{
        temp=to_string(lastPos);
    }

    result.push_back(make_result_string(leftParenthesis, temp, "+", ")"));
    for(string s: result){
        cout << s << '\n';
    }
}



    



    

/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;
 
vector< pair<int, int> > points;
int Answer;
int k;

int calAbs(int i, int x, int y){
    // cout << points[i].first << " " << points[i].second << '\n';

    return abs(points[i].first-x)+abs(points[i].second-y);
}

int eval(int x, int y, int min){
    int result=0;

    result+= calAbs(0, x, y);
    if(result >min ) return -1;
    result+= calAbs(1, x, y+k);
    if(result >min ) return -1;
    result+= calAbs(2, x+k, y+2*k);
    if(result >min ) return -1;
    result+= calAbs(3, x+2*k, y+2*k);
    if(result >min ) return -1;
    result+= calAbs(4, x+3*k, y+k);
    if(result >min ) return -1;
    result+= calAbs(5, x+3*k, y);
    if(result >min ) return -1;
    result+= calAbs(6, x+2*k, y-k);
    if(result >min ) return -1;
    result+= calAbs(7, x+k, y-k);
    if(result >min ) return -1;
    
    return result;
}

int cmp(pair<int, int>& a , pair<int, int>&b){
    if(a.first+a.second == b.first+b.second){
        return a.first < b.first;
    }
    return a.first+a.second < b.first+b.second;

}


int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        Answer=999999;

        points.clear();
        // cout << points[0].first;
        cin >> k;
        int xsum=0;
        int ysum=0;
        for(int i=0;i<8;i++){
            int x, y;
            cin >> x >> y;
            xsum+=x;
            ysum+=y;
            points.push_back(make_pair(x, y));
        }

        xsum/=8;
        ysum/=8;

        sort(points.begin(), points.end(), cmp);



        for(int i=xsum-2*k;i<xsum;i++){
            for(int j=ysum-k;j<ysum;j++){
                
                int result=eval(i, j, Answer);
                if(result>0){
                    Answer=result;
                }
                // do{
                //     int result=eval(i, j, Answer);
                //     if(result>0){
                //         Answer=result;
                //     }
                // }while(next_permutation(points.begin(), points.end()));
            }
        }





		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
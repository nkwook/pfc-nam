/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
// #include <time.h>

using namespace std;

int target[1801][1801]; // too big?
int Answer;
queue< pair<int, int > > Q;

int calAbs(int x, int y, int tx, int ty){
    return abs(x-tx)+abs(y-ty);
}

int main(int argc, char** argv)
{
	int T, test_case;
    // time_t start, end;
    // start=time(NULL);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

        int n, k;
        cin >> n  >> k;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> target[k+i][k+j];
            }
        }
		Answer = 0;

        //upper left
        for(int d=1;d<k;d++){
            // k,k ~ k+l, k
            int sum=0;
            for(int i=0;i<k-d;i++){
                for(int j=0;j<i+1;j++){
                    if(i-j<n && j<n){ //나갈때 
                        sum+=(k-d)*target[k+i-j][k+j];
                    }
                }
            }
            if(sum>Answer){
                Answer=sum;
            }
        }

        //upper right
        for(int d=1;d<k;d++){
            // k,k ~ k+l, k
            int sum=0;
            for(int i=0;i<k-d;i++){
                for(int j=0;j<i+1;j++){
                    if(i-j<n && j<n){ //나갈때 
                        sum+=(k-d)*target[k+(i-j)][k+n-1-j];
                    }
                }
            }
            if(sum>Answer){
                Answer=sum;
            }
        }

        //lower left
        for(int d=1;d<k;d++){
            // k,k ~ k+l, k
            int sum=0;
            for(int i=0;i<k-d;i++){
                for(int j=0;j<i+1;j++){
                    if(i-j<n && j<n){ //나갈때 
                        sum+=(k-d)*target[k+n-1-(i-j)][k+j];
                    }
                }
            }
            if(sum>Answer){
                Answer=sum;
            }
        }

        //lower right
        for(int d=1;d<k;d++){
            // k,k ~ k+l, k
            int sum=0;
            for(int i=0;i<k-d;i++){
                for(int j=0;j<i+1;j++){
                    if(i-j<n && j<n){ //나갈때 
                        sum+=(k-d)*target[k+n-1-(i-j)][k+n-1-j];
                    }
                }
            }
            if(sum>Answer){
                Answer=sum;
            }
        }

        //k, k
        int initsum=0;
        for(int i=0;i<k;i++){
            for(int j=0;j<i;j++){
                initsum+=(k-i)*target[k+i-j][k+j];
            }
        }


        for(int i=k;i<n+k;i++){

            for(int j=k;j<n+k;j++){
                for(int di=0;di<k;di++){
                    for(int dj=0;dj<k;dj++){

                    }
                }

                

                // for(int di=k;di<n+k;di++){
                //     for(int dj=k;dj<n+k;dj++){
                //         int multiple=k-calAbs(i, j, di, dj);
                //         if(multiple>0){
                //             sum+=multiple*target[di][dj];
                //         }
                //     }
                // }
                if(sum>Answer){
                    Answer=sum;
                }

            }
        }

             // for(int di=k;di<k+n;di++){
                //     for(int dj=k;dj<k+n;dj++){
                //         int dist=k-calAbs(i, j, di, dj);
                //         if(dist >0){
                //            sum+=dist * target[di][dj];
                //         }
                //     }
                // }


        

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
    // end=time(NULL);
    // cout << (double)(end-start) << " ?";
	return 0;//Your program should return 0 on normal termination.
}
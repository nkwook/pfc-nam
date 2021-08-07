/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
using namespace std;

int Answer;
int a[50001];
int b[50001];
int used[50001];

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        int n, tt;
        string bstr;

        cin >> n >> tt >> bstr;


        for(int i=1;i<=n;i++){
            a[i]=0;
            used[i]=0;
        }
        
        int i=1;

        for(char c: bstr){
            b[i]=c-'0';
            i++;
        }

        // 이미 아는 2t?개
        int cnt=tt;
        if(n-tt<tt){
            cnt=n-tt;
        } 
        for(int i=1;i<=cnt;i++){
            a[i+tt]=b[i];
            a[n-i-tt+1]=b[n-i+1];
            // used[i+tt]=1;
            // used[n-i-tt+1]=1;
        }

        for(int i=cnt+1; i<=n-cnt;i++){
            if(b[i]==1){
                if(a[i-tt]==1) continue;
                if(i+2*tt <= n){
                    if(!b[i+2*tt]){
                        a[i-tt]=1;
                    }else{
                        a[i+tt]=1;
                    }
                }else{
                    a[i+tt]=1;
                }
            }
        }

		cout << "Case #" << test_case+1 << endl;
        for(int i=1;i<=n;i++){
            cout << a[i];
        }
        cout << endl;

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		// cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
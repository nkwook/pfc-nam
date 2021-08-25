/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <cmath>
using namespace std;

long long Answer;

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
        long long r;
        cin >> r;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
        Answer+=((r+2)*(r+1)/2 -2)*4-(r-1)*4-3;
        // cout << Answer << " !!\n";

        
        for(long long i=1;i<r;i++){
            // for( int j=r-i+1;j*j<r*r-i*i;j++){
            //     Answer+=4;
            // }

            Answer+=4*(floor((long long)sqrt(double(r*r-i*i)))-(r-i));            
            if(abs(floor(sqrt(double(r*r-i*i)))-sqrt(double(r*r-i*i))) < 1e-12){
                Answer-=4;
            }
        }


		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
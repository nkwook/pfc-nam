/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;
vector<int> v[500];

int main(int argc, char** argv)
{
	int T, test_case;


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n, k;
        string str;
        cin >> str;
		Answer = 0;
        for(int i=1;i<=k;i++){
            string pat;
            cin >> pat;

            for(auto c:pat){
                
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

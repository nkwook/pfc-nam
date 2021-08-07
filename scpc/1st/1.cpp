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
int visit[100001];
// vector<int> graph[100001];
int mark[1000001];

int dfs(int x){
	// cout << x << " " << mark[x] << "\n";
	if(mark[x]==0) return 0;

	if(visit[mark[x]]){
		return -1;
	}
	visit[mark[x]]=1;
	return dfs(mark[x]);
}

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
	   But before submission, you m`ust remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		int n;
		cin >> n;

		for( int i=1;i<=n;i++){
			visit[i]=0;	
			mark[i]=0;
			// graph[i].clear();
		}
        for(int i=1;i<=n;i++){
			int x;
			cin >> x;
			x+=i;
			if(x<=n){
				// cout << x << ",";
				mark[i]=x;
			}
		}

		for(int i=1;i<=n;i++){
				// cout << "\n";
			// cout << visit[i] << " ? ";

			// dfs(1)
			if(visit[i] && mark[i]==0) continue; //end
			Answer++;
			Answer+=dfs(i);

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

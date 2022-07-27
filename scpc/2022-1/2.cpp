
#include <iostream>
#include <vector>
using namespace std;

int Answer;
int n, k;
bool vis[5001][5001];
int dp[5001][5001];

int backtrack(vector<int>& v, int target, int prefixSum, int pos, int portions, int divv){
    if(pos==v.size()){
        if(portions==divv) return 1;       
        else return 0;
    }
    // cout << prefixSum << ' ' << pos << ' ' << portions << '\n';

   
    if(portions==divv && pos!=v.size()){
        return 0;
    }
    if(vis[pos][portions]) return dp[pos][portions];
    vis[pos][portions]=true;
    
    prefixSum+=v[pos];


    if(prefixSum==target*(portions+1)){
        dp[pos][portions]+=backtrack(v, target, prefixSum, pos+1, portions+1, divv);
    }
    dp[pos][portions]+=backtrack(v, target, prefixSum, pos+1, portions, divv);

    return dp[pos][portions]%1000000007;
}
       

int main(int argc, char** argv)
{
	int T, test_case;
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
	// freopen("input.txt", "r", stdin);
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    
	    Answer = 0;
        
        cin >> n >> k;
        int divv=k;
        if(n<=5000){
            for(int i=0;i<n;i++){
                for(int j=0;j<k;j++){
                    vis[i][j]=false;
                    dp[i][j]=0;
                }
            }
        }
        vector<int> v;
        int x;
        int sum=0;
        for(int i=0;i<n;i++){
            cin >> x;
            v.push_back(x);
            sum+=x;
        }

        if(n>5000){
                // Print the answer to standard output(screen).
            cout << "Case #" << test_case+1 << endl;
            cout << Answer << endl;
            continue;
        }
        
        if(sum%divv != 0) {
            cout << "Case #" << test_case+1 << endl;
		    cout << Answer << endl;
            continue;
        }
        int partSum=sum / divv;
        Answer=backtrack(v, partSum, 0, 0, 0, divv);
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
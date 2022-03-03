
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.size();
        int n=needle.size();
        if(n==0) return 0;
        for(int i=0;i<=h-n;i++){
            for(int j=0;j<n;j++){
                if(haystack[i+j]!=needle[j]) break;
                if(j==n-1) return i;
            }
        }
        return -1;
    }
};


using namespace std; //kmp!!!!
#include <iostream>
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        vector<int> pi=getPi(needle);
        int i=0;
        int j=0;
        // for(int x:pi){
        //     cout << x << ' '; 
        // }            
        while(i+j<haystack.size()){
            // cout << i << ' ' << j << '\n';
            if(haystack[i+j]==needle[j]){
                j++;
            }else{
                if(j==0){
                    i++;
                }else{
                    i+=j-pi[j-1];
                    j=pi[j-1];
                }
            }
            
            if(j==needle.size()) return i;
        }   
        return -1;
    }
    
    vector<int> getPi(string needle){
        int n=needle.size();
        vector<int> pi(n, 0);
        int j=0;
        for(int i=1;i<n;i++){
            while(j>0 && needle[i]!=needle[j])
                j=pi[j-1];
            if(needle[i]==needle[j]){
                j++;
                pi[i]=j;                
            }
        }
        
        
        return pi;
    }
};





int main(){
    Solution s;
    // vector<int> n{2, 3, 5}
    int t=5;
    int r=s.strStr("ababcaababcaabc", "ababcaabc");

    cout <<r ;
}
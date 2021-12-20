#include <iostream>
using namespace std;
#include <list>
#include <string>

list<char> l;

// why wrong when blank?


class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if('A'<=c && 'Z'>=c) {
                c+=32;
            }

            if('a'<=c && 'z'>=c){
                l.push_back(c);
            }
        }

        if(l.empty()) return true;

        while(!l.empty() && l.size()!=1){
            // cout << l.front() << ' ' << l.back() << '\n';
            if(l.front() != l.back()){
                return false;
            }
            l.pop_front();
            l.pop_back();

        }
        return true;

        
    }
};


int main(){
    Solution s;
    string str;
    cin >> str;
    // vector<int> n{2, 3, 5}
    // int t=5;
    // vector<int> r=s.twoSum(n, t);

    // for(int i: r)
    cout << to_string(s.isPalindrome(str));


}
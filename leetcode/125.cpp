#include <iostream>
using namespace std;
#include <list>
#include <string>



class Solution {
public:
    bool isPalindrome(string s) {
        list<char> l;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if('A'<=c && 'Z'>=c) {
                c+=32;
            }

            if(('a'<=c && 'z'>=c) || ('0'<=c && '9'>=c)){
                l.push_back(c);
            }
        }

        if(l.empty() || l.size()==1) return true;

        while(!l.empty() && l.size()!=1){
            if(l.front() != l.back()){
                return false;
            }
            l.pop_front();
            l.pop_back();

        }
        return true;

        
    }
};



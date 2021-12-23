#include <iostream>
using namespace std;
#include <list>
#include <string>

// 그대로 스트링으로 하는것이 더 효율적 
// 불필요한 자료구조와 알고리즘을 사용하지 않는것이 더 좋음
// 불필요한 이중 조건문 등도 유의할 것

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



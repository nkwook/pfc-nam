class Solution {
public:
    int calculate(string s) {

        // stack implementation. more fast and readable. 
        // trick: use "i==s.length()-1" then we dont need extra conditional statements
        // use isdigit, isspace function
        // calculator problems: stacks are good because we need prior info of numbers. 
        // calculation can be proceeded when theres both operator, operand
        // Also pleaz remember way to subtract zero... mㅡㅡㅡㅡㅡ
        stack<int> stk;
        int tmp=0;
        char op='+';
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                tmp=tmp*10-'0'+s[i]; //prevent int overflow
            }
            if((!isspace(s[i]) && !isdigit(s[i]) )|| i==s.length()-1){
                
                if(op=='+'){
                    stk.push(tmp);
                }else if(op=='-'){
                    stk.push(-tmp);
                }else if(op=='*'){
                    tmp*=stk.top();
                    stk.pop();
                    stk.push(tmp);
                }else if(op=='/'){
                    int num=stk.top()/tmp; 
                    stk.pop();
                    stk.push(num);
                }
                op=s[i];
                tmp=0;
            }
        }
        stk.push(tmp);
        int result=0;
        while(!stk.empty()){
            result+=stk.top();
            stk.pop();
        }
        return result;
        
    }
};


class Solution {
public:
    int calculate(string s) {
        string num1="";
        string num2="";
        string afterM="";
        char op;
        bool isMul=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='+' || s[i]=='-'){
                if(isMul){
                    if(op=='*') num1=to_string(stoi(num1)*stoi(num2));
                    else  num1=to_string(stoi(num1)/stoi(num2));
                    isMul=false;
                }
                afterM+=num1+s[i];
                num2="";
                num1="";
            }else if(s[i]=='*' || s[i]=='/'){
                if(isMul){
                    if(op=='*') num1=to_string(stoi(num1)*stoi(num2));
                    else  num1=to_string(stoi(num1)/stoi(num2));
                }
                num2="";
                isMul=true;
                op=s[i];
            }else if(isMul){
                num2+=s[i];
            }else{
                num1+=s[i];
            }    
        }   
        if(num2!=""){
            if(op=='*') {
                num1=to_string(stoi(num1)*stoi(num2));
            }
            else  num1=to_string(stoi(num1)/stoi(num2));
        }
        afterM+=num1;
        num1="";

        int result=0;
        op='+';
        for(int i=0;i<afterM.length();i++){
            if(afterM[i]=='+' || afterM[i]=='-'){
                if(op=='+') result+=stoi(num1);
                else result-=stoi(num1);
                op=afterM[i];
                num1="";
            }else{
                num1+=afterM[i];
            }
        }
        if(op!='-' ) result+=stoi(num1);
        else result-=stoi(num1);
        
        return result;
        
    }
};
#include <iostream>
#include <list>

using namespace std;

int main(){
    string initialString;
    int number;
    cin >> initialString >> number;
    cin.ignore(); // clear buffer

    string commands[number];
    for(int i=0;i<number;i++){
        getline(cin, commands[i]);
    }

    list<char> Editor;
    
    for(char c: initialString){
        Editor.push_back(c);
    }

    // Q. why we cant print iterator out dislike as int case?
    // => Ah I was wrong... cause first .end() event, that should be
    // print out space. 
    // we have to know feature of .end() => also cursor--; in erase is reasonable then. 

    auto cursor=Editor.end();
    // cout << *cursor << "?";
    
    for(int j=0;j<number;j++){
        cout << *cursor << " ";
        if(commands[j][0]=='L'){
            if(cursor!=Editor.begin()) cursor--;
        }else if(commands[j][0]=='D'){
            if(cursor!=Editor.end()) cursor++;
        }else if(commands[j][0]=='B'){
            if(cursor!=Editor.begin()){
                cursor--; // 
                cursor=Editor.erase(cursor);
            }
        }else{
            Editor.insert(cursor, commands[j][2]);
        }
    }
    
    for(auto cc: Editor){
        cout << cc;
    }


}
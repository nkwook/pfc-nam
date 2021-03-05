#include <iostream>
using namespace std;

int main(){
    string a, b;
    int result=0;
    int arr[26]={};
    cin >> a >> b;
    // use difference
    for(char achar: a){
        arr[achar-'a']++;
    }
    for( char bchar: b){
        arr[bchar-'a']--;
    }
    for(int i=0;i<26;i++){
        if(arr[i]<0){
            result-=arr[i];
        }else{
            result+=arr[i];
        }
    }
    cout << result;


}
#include <iostream>
using namespace std;

int main(){
    int number, k, gender, grade, result;
    cin >> number >> k;
    int student[2][6]={};
    // int girl[6]={};
    result=0;
    // get input and categorize 
    for(int i=0;i<number;i++){
        gender=0;
        grade=0;
        cin >> gender >> grade;
        if(gender){
            student[1][grade-1]++;
        }else{
            student[0][grade-1]++;
        }
    }
    for(int j=0;j<2;j++){
        for(int l=0;l<6;l++){
            int temp=student[j][l];
            while(temp>0){
                result++;
                temp-=k;
            }
        }
    }
    cout << result;

}
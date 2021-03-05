#include <iostream>
using namespace std;

int main(){
    int number;
    int element[10]={};
    cin >> number;

    
    while(number>0){
        element[number%10]++;
        number/=10;
    }
    int max=0;
    int comp=0;
    if(number==0){
        max=1;
    }

    for(int i=0;i<9;i++){
        if(i==6){
            comp=(element[i]+element[9]+1)/2;
            max= comp > max ? comp: max; 
        }else{
            max= element[i]>max ? element[i]: max;
        }
    }
    cout << max;


}
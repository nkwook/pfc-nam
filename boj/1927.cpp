#include <iostream>
using namespace std;

int heap[300001]={0};
int sz=0;
int temp=0;
int n, x;

// writing recursive form is better to understand
// need to test more cases.....  even from basic ones

void pushRecur(int t, int end){
    if(end==1 || heap[end/2]<=t) return;

    heap[end]=heap[end/2];
    heap[end/2]=t;
    pushRecur(t, end/2);
    return;
}

void push(int t){
    sz++;
    heap[sz]=t;


    pushRecur(t, sz);
    return;
}


int min(int a){
    if(heap[a]==0) return 0;
    else if(heap[a+1]==0) return a;
    else if(heap[a]>heap[a+1]) return a+1;
    else return a;
}

void swap(int a, int b){
    temp=heap[a];
    heap[a]=heap[b];
    heap[b]=temp;
    return;
}
void eraseRecur(int parent, int minimum){
    if(heap[minimum]==0 || heap[parent] <= heap[minimum]) return;
    swap(parent, minimum);
    eraseRecur(minimum, min(minimum*2));
    return;
}

void erase(){
    if(sz==0){
        cout << 0 << '\n';
        return;
    }
    cout << heap[1] << '\n';

    heap[1]=heap[sz];
    heap[sz]=0;
    sz--;
    eraseRecur(1, min(2));
    return;
}

void print(){

    for(int i=1;i<=sz;i++){
        cout << heap[i] << ' ';
    }
    cout << '\n';
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        cin >> x;

        if(x==0){
            erase();
        }else{
            push(x);
        }
        // print();

    }
    return 0;

}
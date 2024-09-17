#include<iostream>
using namespace std;

/*
1
2 3
4 5 6
7 8 9 10
 */
int main(){
    int num;
    cout<<"Enter the size: ";
    cin>>num;
    int a=1;
    for(int i=0; i<num; i++){
        for(int j=0; j<i+1; j++){
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }
    return 0;
}
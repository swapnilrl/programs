#include<iostream>
using namespace std;

/*

A
B C
D E F
G H I J
 */
int main(){
    int num;
    cout<<"Enter the size: ";
    cin>>num;
    char ch='A';
    for(int i=0; i<num; i++){
        for(int j=0; j<i+1; j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
    return 0;
}
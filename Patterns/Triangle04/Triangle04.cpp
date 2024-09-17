#include<iostream>
using namespace std;

/*
A
A B
A B C
A B C D
 */
int main(){
    int num;
    cout<<"Enter the size: ";
    cin>>num;

    for(int i=0; i<num; i++){
        char ch='A';
        for(int j=0; j<i+1; j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
    return 0;
}
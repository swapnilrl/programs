#include<iostream>
using namespace std;

/*
        A     
      B C   
    D E F 
  G H I J
K L M N O
 */
int main(){
    int num;
    cout<<"Enter the size: ";
    cin>>num;

    for(int i=0; i<num; i++){
        for(int j=0; j<i+1; j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
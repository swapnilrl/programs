#include<iostream>
using namespace std;

/*
      1
    2 1 2
  3 2 1 2 3
4 3 2 1 2 3 4

 */
int main(){
    int num;
    cout<<"Enter the size: ";
    cin>>num;

    for(int i=0; i<num; i++){
        for(int j=0; j<num-i-1; j++){ //spaces
            cout<<" ";
        }
        for(int j=1; j<=i+1; j++){
            cout<<j;
        }
        for(int j=i; j>0; j--){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}
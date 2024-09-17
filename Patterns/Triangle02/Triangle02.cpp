#include<iostream>
using namespace std;

/*
1
1 1
1 1 1
1 1 1 1
1 1 1 1 1
 */
int main(){
    int num;
    cout<<"Enter the size: ";
    cin>>num;

    for(int i=0; i<num; i++){
        for(int j=0; j<i+1; j++){
            cout<<"1"<<" ";
        }
        cout<<endl;
    }
    return 0;
}
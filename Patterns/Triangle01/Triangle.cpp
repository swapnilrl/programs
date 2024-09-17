#include<iostream>
using namespace std;

/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
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
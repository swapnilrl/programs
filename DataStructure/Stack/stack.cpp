// Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.

#include<iostream>
using namespace std;

#define max 5

class Stack{
    int top;
    int s[max];

    public:
    //constructor
    Stack(){ top = -1;}

    //function to check stack overflow/full
    bool Isfull(){
        if(top >= max-1){
            return 1;
        }
        return 0;
    }

    //function to check stack underflow/empty
    bool IsEmpty(){
        if(top<0){
            cout << "Stack is empty" << endl;
            return 1;
        }
        return 0;
    }

    //function to push element into the stack
    void push(int x){
        if(Isfull()){ 
            cout<<"Stack full"<<endl;
            return;
        }
        s[++top] = x;
        cout<<"Pushed: "<<x<<" to stack"<<endl;
    }

    //function to  pop element from the stack
    int pop(){
        if(!IsEmpty()){
            cout<<"Stack is Empty"<<endl;
            return 0;
            
        }
        return(s[top--]);
    }

    // Function to return the top element of the stack
    int peek()
    {
        // If the stack is empty, print "Stack is empty" and
        // return 0
        if (IsEmpty()) {
            
            return 1;
        }
        // Return the top element of the stack
        return s[top];
    }

};


// Main function
int main()
{
    // Create a stack
    Stack s;
    // Push elements into the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    // Print the top element of the stack
    cout << "Top element is: " << s.peek() << endl;
    // Print all elements in the stack
    return 0;
}
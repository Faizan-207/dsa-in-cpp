#include <iostream>
using namespace std;


int top = -1;
int stack_arr[5];

void push (int data){
    if (top >= 4 )
    {
        cout <<"Stack overFolw!";
        return;
    }
    
    top += 1;
    stack_arr[top] = data;
    
}

void pop (){
    if (top == -1 )
    {
        cout<<"Stack underFlow";
        return;
    }
    top -= 1;
}

bool isFull (){
    if (top >= 4)
    {
        cout<<"Stack is full!"<<endl;
        return true;
    }
    else 
    return false;
    
}

bool isEmpty(){
    if (top == -1)
    {
        cout<<"Stack is Empty!"<<endl;
        return true;
    }
     return false;
}

int peek(){
    if (top == -1)
    {
        cout<<"Stack is Empty!";
        return 1;
    }
    return stack_arr[top];
    
}


void display (){
    if (top == -1)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    
    for (int i = top ; i >=0 ; i--)
    {
        cout<<stack_arr[i]<<"  ";
    }

    
}

int main (){
    push(11);
    push(22);
    push(33);
    push(44);
    push(55);
    pop();
    cout<<peek()<<endl;
    cout <<isFull()<<endl;
    cout <<isEmpty()<<endl;
    

    display();


    return 0;

}
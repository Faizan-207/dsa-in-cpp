#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class stack{
    private:
        node *top;
    public:
        stack(){
            top = NULL;
        }

    void push(int data){
        node *newnode = new node();
        newnode -> data = data;

        if (top == NULL)
        {
            top = newnode;
            newnode -> next = NULL;
            return;
        }
        newnode -> next = top;
        top = newnode;
    }

    void pop(){
        if (top == NULL)
        {
            cout<<"Stack is empty!";
            return;
        }
        node *temp = top ;
        top = top -> next;
        delete temp;

    }

    int peek(){
        if (top == NULL){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return top -> data;
    }

    int isempty(){
        if (top == NULL)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    
    void display (){
        node *curr = top;
        while(curr)
        {
            cout<< curr -> data<<" ";
            curr = curr -> next;

        }

    }

};

int main (){

    stack obj;
    obj.push(5);
    obj.push(6);
    obj.push(7);
    obj.push(8);
    cout<<"Before poping"<<endl;
    obj.display();
    obj.pop();
    cout<<"\nAfter poping"<<endl;
    obj.display();
    cout<<"\nPeek element is: "<<obj.peek();
    cout<<"\nIs stack is empty: "<<obj.isempty();



    
}
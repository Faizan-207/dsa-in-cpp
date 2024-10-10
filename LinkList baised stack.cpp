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
            newnode = top;
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
            cout <<curr -> data<<" ";
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
    obj.display();

    obj.pop();
    
}
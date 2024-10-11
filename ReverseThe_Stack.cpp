#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class stack {
     
     public:
    node* push(int data , node *top){
        node *newnode = new node();
        newnode -> data = data;
        
        if (top == NULL){
            top = newnode;
            newnode -> next = NULL;
            return top;
        }
        newnode -> next = top;
        top = newnode;
        return top;
        }
    node* pop(node *top){
        if (top == NULL){
            cout<<"Stack underflow!\n";
            return top;
        }
        node *temp = top;
        top = top -> next ;
        delete temp;
        return top;

    }
    void display(node *top){
        node *curr = top;
        if (top == NULL){
            cout<<"Stack underflow!\n";
            return;
        }
        while(curr){
            cout <<curr -> data <<" ";
            curr = curr-> next;
        }

    }

     
};



int main (){
    node *top = NULL;
    node *top1 = NULL;
    node *top2 = NULL;

    stack obj;
    top = obj.push(3,top);
    top = obj.push(4,top);
    top = obj.push(5,top);
    obj.display(top);
    top = obj.pop(top);

    

}
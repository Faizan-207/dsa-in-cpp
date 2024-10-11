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
            exit(1);
        }

        node *temp = top;
        top = top -> next ;
        return temp;

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
        cout<<"\n";

    }

     
};



int main (){
    node *temp = NULL;
    node *top = NULL;
    node *top1 = NULL;
    node *top2 = NULL;

    stack obj,temp1,temp2;
    top = obj.push(1,top);
    top = obj.push(2,top);
    top = obj.push(3,top);

    temp = obj.pop(top);
    top = temp-> next;
    top1 = obj.push(temp->data,top1);

    temp = obj.pop(top);
    top = temp-> next;
    top1 = obj.push(temp->data,top1);

    obj.display(top);
    obj.display(top1);




    

}
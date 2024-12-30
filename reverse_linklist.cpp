#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linklist
{
    node *head, *curr;

public:
    linklist()
    {
        head = NULL;
        curr = NULL;
    }

    void insert_at_end(int data)
    {
        node *newnode = new node();
        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newnode;
        }
    }
    void reverselinklist()
    {
        node *prev = nullptr;
        node *current = head;
        node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void display()
    {
        curr = head;
        while (curr)
        {
            cout << curr->data << "->";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{

    linklist obj;
    obj.insert_at_end(1);
    obj.insert_at_end(2);
    obj.insert_at_end(3);
    obj.insert_at_end(4);
    obj.insert_at_end(5);
    obj.insert_at_end(6);
    cout << "Before reverse" << endl;
    obj.display();
    obj.reverselinklist();
    cout << "After reverse" << endl;
    obj.display();
}
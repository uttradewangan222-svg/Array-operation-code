#include<iostream>
#include<string>
using namespace std;

struct Node
{
    int data;
    struct Node *link;
    struct Node *prev;
};

void Traversal(struct Node *head)
{
    while(head != NULL)
    {
        cout << "Data :" << head->data << endl;
        head  = head->link;
    }
}

struct Node * Insertion_after(struct Node *head, struct Node *node, int item)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = item;
    ptr->link = node->link;
    ptr->prev = node;
    node->link = ptr;
    ptr->link->prev = ptr;
    return head;
}

struct Node * Insertion_before(struct Node *head, struct Node *node, int item)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = item;
    ptr->prev = node->prev;
    node->prev = ptr;
    ptr->link = node;
    ptr->prev->link = ptr;
    return head;
}

struct Node * Deletion_after(struct Node *head, struct Node *node)
{
    struct Node *ptr = node->link;
    node->link =  ptr->link;
    ptr->link->prev = node;
    free(ptr);
    return head;
}

struct Node * Deletion_before(struct Node *head, struct Node *node)
{
    struct Node *ptr = node->prev;
    node->prev = ptr->prev;
    ptr->prev->link = node;
    free(ptr);
    return head;
}

int main()
{
    int ans, work, item;
    string where;
    struct Node *ptr;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->link = first;
    first->prev = head;
    first->link = second;
    second->prev = first;
    second->link = third;
    third->link = NULL;
    third->prev = second;

    ptr = head;
    cout << "Please enter the element of linked list first : "<< endl;
    while(ptr != NULL)
    {
        cin >> ptr->data;
        ptr = ptr->link;
    }

    do
    {
        cout << "Please enter which operation you wnat to do : Press \n 1 for Traversing. \n 2 for Inserting. \n 3 for Deleting."<< endl;
        cin >> work;
        switch(work)
        {
             case 1 : 
                Traversal(head);
                break;
            case 2 :
                cout << "Please enter the item you want Insert : " << endl;
                cin >> item;
                cout << "where you want to insert  the item : After or Before." << endl;
                cin.ignore();
                getline(cin,where);
                if(where == "After")
                    head = Insertion_after(head, second, item);
                else
                    head = Insertion_before(head, third, item);
                break;
            case 3 :
                cin.ignore();
                cout << "From where you want to Delete  the data : After or Before." << endl;
                getline(cin,where);
                if(where == "After")
                    head = Deletion_after(head, second);
                else
                    head = Deletion_before(head, third);
                break;
            default :
                cout << "Invalid input !!!";
                break;
        }    
        cout << "Do you want to continue Press 1 for yes and 0 for No." << endl;
        cin >> ans;
    } while (ans == 1);
    
}

#include<iostream>
using namespace std;

// making of linked list 
struct Node
{
    int data;
    struct Node *link;
};

void Traversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        cout << "data :" << ptr->data << endl;
        ptr = ptr->link;
    }
}

struct Node * Insertion_after(struct Node *ptr, struct Node *node, int item)
{
    if(node == NULL)
    {
        cout << "Please Enter the right node."<< endl;
    }
    else
    {
        struct Node *New = (struct Node *)malloc(sizeof(struct Node));
        New->data = item;
        New->link = node->link;
        node->link = New;
    }
    return ptr;
}

struct Node * Deletion_after(struct Node *head, struct Node *node)
{
    struct Node *ptr = node->link;
    node->link = ptr->link;
    free(ptr);
    return head;
}

int main()
{
    int ans, item, work;
    struct Node *ptr;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    //Linking each node to each other
    head->link = first;
    first->link = second;
    second->link = third;
    third->link = NULL;
    ptr = head;
    cout << "Enter the data in linked list."<<endl;
    while(ptr != NULL)
    {
        cin >> ptr->data;
        ptr = ptr->link;
    }
    
    do
    {
        cout << "Please enter the what work you want to do : Press \n 1 for Traversing. \n 2 for Inserting. \n 3 for Deleting."<<endl;
        cin >> work;
        switch(work)
        {
            case 1 : 
                Traversal(head);
                break;
            case 2 :
                cout << "Please enter the item you want Insert : " << endl;
                cin >> item;
                head = Insertion_after(head, third, item);
                break;
            case 3 :
                head = Deletion_after(head, second);
                break;
            default :
                cout << "Invalid input !!!";
                break;
        }
        cout << "Do you want to continue : Press 1 for Yes and 0 for No." << endl;
        cin >> ans;
    }
    while (ans == 1);
}
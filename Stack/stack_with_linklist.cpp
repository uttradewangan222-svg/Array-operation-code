#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Node * PUSH_LL(struct Node *top)
{   
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    int item;
    cout << "Please enter the element you want to Push : " << endl;
    cin >> item;
    if(ptr==NULL)
    {
        cout << "Stack Overflow !!!" << endl;
        return top;
    }
    else
    {
        ptr->data = item;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

struct Node * POP_LL(struct Node *top)
{
    struct Node *ptr = top;
    top = top->next;
    free(ptr);
    return top;
}

void Display(struct Node *top)
{
    cout << "Here is your stack data : " << endl;
    while(top!=NULL)
    {
        cout << top->data << endl;
        top = top->next;
    }
}

int main()
{
    int work,ans, item;
    struct Node *top = NULL; 
    do
    {
        cout << "Please enter what work you want to do : press \n1 fo Push \n2 for Pop \n3 for peek. "<< endl;
        cin >> work;
        switch(work)
        {
            case 1:
                top = PUSH_LL(top);
                Display(top);
                break;
            
            case 2:
                if(top==NULL)
                {
                    cout << "Sorry element cannot be Deleted, the Stack is Empty !!!" << endl;
                }
                else
                {
                    top = POP_LL(top);
                }
                Display(top);
                break;

            case 3:
                Display(top);
                break;

            default:
                cout << "Please Enter the right work value !!!" << endl;
        }
        cout << "Do you want to continue : press 1/0" << endl;
        cin >> ans;
    }
    while(ans==1);

    


    return 0;
}